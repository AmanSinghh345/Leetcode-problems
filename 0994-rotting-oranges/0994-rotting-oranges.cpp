class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};

        vector<vector<int>> vis(m,vector<int> (n,0));
        queue<pair<pair<int,int>,int>> q;
        int time=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }
        
        while(!q.empty())
        {
            auto curr=q.front();
            q.pop();
            int row=curr.first.first;
            int col=curr.first.second;
            int t=curr.second;

            time=max(time,t);
            
            for(int i=0;i<4;i++)
            {
                
                
                    int nrow=row+dx[i];
                    int ncol=col+dy[i];
                    if(nrow>=0 and nrow<m and ncol>=0 and ncol<n and vis[nrow][ncol]==0 and grid[nrow][ncol]==1){
                        vis[nrow][ncol]=1;
                        grid[nrow][ncol]=2;
                        q.push({{nrow,ncol},t+1});
                     
                    }
                
            }

        }

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1) return -1;
            }
        }
        return time;

    }
};