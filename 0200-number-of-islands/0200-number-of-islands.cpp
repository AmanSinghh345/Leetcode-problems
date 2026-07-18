class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        vector<vector<int>> vis(m,vector<int>(n,0));
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if( grid[i][j]=='1' && !vis[i][j]){
                    cnt++;
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    while(!q.empty()){
                        auto it=q.front();
                        q.pop();
                        int x=it.first;
                        int y=it.second;
                        if(vis[x][y]) continue;
                        vis[x][y]=1;
                        for(int k=0;k<4;k++){
                            int nx=x+dx[k];
                            int ny=y+dy[k];
                            if(nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny]=='1' &&  !vis[nx][ny]){
                                q.push({nx,ny});
                            }
                        }
                    }
                }
            }
        }
        return cnt;
    }
};