class Solution {
public:
    class DSU{
        public:
        int n;
        vector<int> size;
        vector<int> parent;
        DSU(int n){
            this->n=n;
            size.assign(n,1);
            parent.resize(n);
            for(int i=0;i<n;i++) parent[i]=i;
        }

        int find(int node){
            if(parent[node]==node) return node;
            return parent[node]=find(parent[node]);
        }

        void UnionBySize(int a,int b){
            int pa=find(a);
            int pb=find(b);
            if(pa==pb) return;
            if(size[pa]>size[pb]){
                parent[pb]=pa;
                size[pa]+=size[pb];
            }
            else {
                parent[pa]=pb;
                size[pb]+=size[pa];
            }
            return;
        }
    };
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
       DSU dsu(n);
       for(int i=1;i<n;i++){
        if(nums[i]-nums[i-1]<=maxDiff) dsu.UnionBySize(i,i-1);
       }  
        vector<bool> ans;
       for(auto it : queries){
        int u=it[0];
        int v=it[1];
        if(dsu.find(u)==dsu.find(v)) ans.push_back(true);
        else ans.push_back(false);
       }
       return ans;
    }
};