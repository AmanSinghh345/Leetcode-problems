struct Node{
    Node* links[2];
    bool containsKey(int key)
    {
        return links[key]!=NULL;
    }
    Node* get(int key)
    {
        return links[key];
    }
    void put(int key,Node* node)
    {
        links[key]=node;
    }
};
class Trie
{
    private: Node* root;
    public: 
    Trie()
    {
        root=new Node();
    }
    void insert(int num)
    {
        Node* node=root;
        for(int i=31;i>=0;i--)
        {
            int bit=(num>>i)&1;
            if(!node->containsKey(bit))
            {
                node->put(bit,new Node());
            }
            node=node->get(bit);
        }
    }
    int maxXorVal(int num)
    {
        Node * node=root;
        int maxi=0;
        for(int i=31;i>=0;i--)
        {
            int bit=(num>>i)&1;
            if(node->containsKey(1-bit))
            {
                maxi=maxi|(1<<i);
                node=node->get(1-bit);
            }
            else node=node->get(bit);
        }
        return maxi;
    }
};
class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        Trie trie;
        int n=nums.size();
        vector<pair<pair<int,int>,int>> offlineQueries;
        for(int i=0;i<queries.size();i++){
            int x=queries[i][0];
            int m=queries[i][1];
            offlineQueries.push_back({{m,x},i});
        }
        sort(offlineQueries.begin(),offlineQueries.end());
        sort(nums.begin(),nums.end());
        vector<int> ans(queries.size(),0);
        int j=0;
        for(int i=0;i<offlineQueries.size();i++)
        {
                while(j<n and nums[j]<=offlineQueries[i].first.first)
                {
                    trie.insert(nums[j]);
                    j++;
                }
                if(j==0)
                {
                    ans[offlineQueries[i].second]=-1;
                }
              else { int val=trie.maxXorVal(offlineQueries[i].first.second);
                ans[offlineQueries[i].second]=val;}
        }
        return ans;
    }
};