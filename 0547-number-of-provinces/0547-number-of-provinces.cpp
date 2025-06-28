class Solution {
public:
    void bfs(int node,vector<vector<int>> &adjMat,int& cnt,vector<int> &vis,queue<int> &q){
        q.push(node);
        vis[node]=1;
        while(!q.empty()){
            node=q.front();
            q.pop();

            for(int i=0;i<adjMat[node].size();i++){
                if(adjMat[node][i]==1 and vis[i]==0){ // means connected not visited
                        q.push(i);
                        vis[i]=1;
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        queue<int> q;
        vector<int> vis(n,0);
        int ans=0;
      

        for(int i=0;i<n;i++){
            if(!vis[i]){
                ans++;
        bfs(i,isConnected,ans,vis,q);
        }
        }

        return ans;
    }
};