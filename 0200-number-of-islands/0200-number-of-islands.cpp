class Solution {
public:
   
    void dfs(int i,int j,vector<vector<char>>& grid){
        int m=grid.size();
        int n=grid[0].size();
        if(i<0 || i>=m) return ;
        if(j<0 || j>=n) return ;
        if(grid[i][j]=='0') return ;
        if(grid[i][j]=='1') grid[i][j]='0';
         const int dx[]={-1,0,1,0};
    const int dy[]={0,1,0,-1};
        for(int k=0;k<4;k++){
            int nx=i+dx[k];
            int ny=j+dy[k];

            dfs(nx,ny,grid);
            

        }
        return;

    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        int cnt=0;
        

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){

                if(grid[i][j]=='1') 
                    {
                        dfs(i,j,grid);
                        cnt++;
                    }
            }
        }
        return cnt;
    }
};