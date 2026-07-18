class Solution {
public:
    class Disjoint{
        public:
        vector<int> parent;
        vector<int> size;
        Disjoint(int n){
            parent.resize(n);
            for(int i=0;i<n;i++) parent[i]=i;
            size.assign(n,1);
        }
        int find(int node){
            if(parent[node]==node) return node;
            return parent[node]=find(parent[node]);
        }
        void UnionBySize(int a,int b){
            int pa=find(a);
            int pb=find(b);
            if(pa==pb) return;
            if(size[pb]>size[pa]) swap(pa,pb);
            size[pa]+=size[pb];
            parent[pb]=pa;
            return;
        }
    };
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        Disjoint dsu(n);
        for(auto& edge:edges){
            int u=edge[0];
            int v=edge[1];
         
            if(dsu.find(u-1)==dsu.find(v-1)) {
                return {u,v};
            }
            dsu.UnionBySize(u-1,v-1);
        }
        return {};
    }
};