class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<vector<int>>>  vis(m,vector<vector<int>> (n,vector<int>(k+1,-1)));

       

        queue<vector<int>> q;
        q.push({0,0,0,k});

        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};

        while(!q.empty()){
            auto it = q.front();
            q.pop();

            int curr=it[0];
            int x=it[1];
            int y=it[2];
            int K=it[3];
            if(x==m-1 && y==n-1) return curr;
            for(int z=0;z<4;z++){
                int nx=x+dx[z];
                int ny=y+dy[z];

                if(nx>=0 && nx<m && ny>=0 && ny<n){
                   
                    int rem=K-grid[nx][ny];
                    
                    if(rem<0) continue;

                    if(vis[nx][ny][rem]==-1){
                        vis[nx][ny][rem]=1;
                        q.push({curr+1,nx,ny,rem});
                    }
                }
            }
        }

       return -1;
    }
};