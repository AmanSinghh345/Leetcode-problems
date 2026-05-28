
class Disjoint{
    public : 
    vector<int> parent;
vector<int> size;
    Disjoint(int n){
        parent.resize(n);
        for(int i=0;i<n;i++) 
            parent[i]=i;
        size.resize(n,1);
    }
    int find(int node){
        if(parent[node]==node) return node;
        return parent[node]=find(parent[node]);
    }
    void unionBySize(int a,int b){
        int pa=find(a);
        int pb=find(b);
        if(pa==pb) return ;
        if(size[pb]<size[pa]){
            parent[pb]=pa;
            size[pa]+=size[pb];
        }
        else{
            parent[pa]=pb;
            size[pb]+=size[pa];
        }
    }
};
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        Disjoint ds(m*n);
        int ans=0;
        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0) continue;

                int node=i*n+j;
                for(int k=0;k<4;k++){
                    int ni=i+dx[k];
                    int nj=j+dy[k];
                    int adjnode=ni*n+nj;
                    if(ni>=0 && ni<m && nj>=0 && nj<n && grid[ni][nj]==1){
                        if(ds.find(node)!=ds.find(adjnode)){
                            ds.unionBySize(node,adjnode);
                        }
                    }
                }


                
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) continue;
               
                unordered_set<int> comps;
                int node=i*n+j;
                for(int k=0;k<4;k++){
                    int ni=i+dx[k];
                    int nj=j+dy[k];
                    int adjnode=ni*n+nj;
                    if(ni>=0 && ni<m && nj>=0 && nj<n && grid[ni][nj]==1){
                        comps.insert(ds.find(adjnode));
                    }
                }
                int curr=1;
                for(auto & it : comps){
                    curr+=ds.size[it];
                }
               ans=max(ans,curr);
            }
        }
        for(int i=0;i<n*n;i++){
           ans=max(ans,ds.size[ds.find(i)]);
        }
        return ans;
    }
};