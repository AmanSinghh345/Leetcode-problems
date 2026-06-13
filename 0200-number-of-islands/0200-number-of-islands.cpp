class Solution {
public:

    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};
        vector<vector<int>> vis(m,vector<int> (n,0));
        queue<pair<int,int>> q;
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    cnt++;
                    q.push({i,j});
                    while(!q.empty()){
                        auto [x,y]=q.front();
                        q.pop();

                        for(int k=0;k<4;k++){
                            int nx=x+dx[k];
                            int ny=y+dy[k];
                            if(nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny]=='1' && !vis[nx][ny] ){
                                q.push({nx,ny});
                                vis[nx][ny]=1;
                            }
                        }
                    }
                }
            }
        }
        return cnt;
    }
};