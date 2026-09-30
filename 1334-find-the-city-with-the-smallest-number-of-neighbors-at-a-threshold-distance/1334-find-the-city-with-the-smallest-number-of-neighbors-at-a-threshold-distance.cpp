class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> adjList(n,vector<int>(n,INT_MAX));
        for(int i=0;i<n;i++){
            adjList[i][i]=0;
        }
        for(auto &it : edges){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            adjList[u][v]=adjList[v][u]=wt;
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(adjList[i][k]!=INT_MAX and adjList[k][j]!=INT_MAX) 
                        adjList[i][j]=min(adjList[i][j],adjList[i][k]+adjList[k][j]);
                }
            }
        }
        int ans=-1;
        int cnt=INT_MAX;
        for(int i=0;i<n;i++){
            int curr=0;
            for(int j=0;j<n;j++){
                if(i!=j and adjList[i][j]<=distanceThreshold){
                    curr++;
                    cout<<curr<<endl;
                }
            }
            cout<<curr<<endl;
            if(curr<=cnt) {
                cnt=curr;
                ans=i;
            }
        }
        return ans;
    }
};