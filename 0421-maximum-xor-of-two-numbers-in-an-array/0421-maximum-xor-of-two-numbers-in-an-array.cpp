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
    private:Node * root;
    public:
    Trie()
    {
        root=new Node();
    }
    void insert(int num)
    {
        Node* node=root;
        for(int i=31;i>=0;i--)
        {   int bit=(num>>i)&1;
            if(!node->containsKey(bit))
            {
                node->put(bit,new Node());
            }
            node=node->get(bit);
        }
    }
    int maxXorVal(int num)
    {
        Node* node=root;
        int maxi=0;
        for(int i=31;i>=0;i--)
        {
            int bit=(num>>i)&1;
            if(node->containsKey(1-bit))
            {
                maxi=(maxi)|(1<<i);
                node=node->get(1-bit);
            }
            else {
                node=node->get(bit);
            }
        }
        return maxi;
    }
};
class Solution {
public:

    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            trie.insert(nums[i]);
        }
        for(int i=0;i<nums.size();i++)
        {
            ans=max(ans,trie.maxXorVal(nums[i]));
        }
        return ans;
    }
};