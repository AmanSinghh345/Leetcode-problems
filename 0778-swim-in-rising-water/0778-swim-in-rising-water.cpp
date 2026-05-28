class Disjoint{
    public: 
    vector<int> parent;
    vector<int> size;
    Disjoint(int n){
        parent.resize(n);
        for(int i=0;i<n;i++) parent[i]=i;
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
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<int> cellPosition(n*n);
        Disjoint ds(n*n);
        vector<pair<int,int>> coordinates(n*n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cellPosition[grid[i][j]]=i*n+j;
                coordinates[grid[i][j]]={i,j};
            }
        }
        int start=0;
        int end=(n-1)*n + (n-1);
        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};
        for(int t=0;t<n*n;t++){
                int i=coordinates[t].first;
                int j=coordinates[t].second;
                int node=i*n+j;
                for(int k=0;k<4;k++){
                    int ni=i+dx[k];
                    int nj=j+dy[k];
                    int adjnode=ni*n+nj;
                    if(ni>=0 && ni<n && nj>=0 && nj<n && grid[ni][nj]<=t){
                        ds.unionBySize(node,adjnode);
                    }
                   
                }
                 if(ds.find(start)==ds.find(end)) return t;
        }
        return -1;
    }
};