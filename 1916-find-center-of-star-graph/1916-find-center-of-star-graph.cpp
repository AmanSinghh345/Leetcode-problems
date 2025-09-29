class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int,int> umap;
        int m=edges.size();
        for(int i=0;i<m;i++)
        {
            umap[edges[i][0]]++;
            umap[edges[i][1]]++;
        }
        int ans=0;
        int cnt=0;
        for(auto it=umap.begin();it!=umap.end();it++)
        {
            if(it->second>cnt)
            {   
                ans=it->first;
                cnt=it->second;
            }
        }
        return ans;
    }
};