class Solution {
public:

    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        // all the cells are node and adjacent values having 1 or 2 are connected and cell which are connected to value 2 will get rotten in 1 sec
        //First I will push all the starting node in queue which is cell which has value 2
        
        queue<pair<pair<int,int>,int>> q; // pair for i and j and next int for time;
         //Next create a visited 2d matrix  for bfs
        vector<vector<int>> vis(m,vector<int> (n,0));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }

        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};

        int time=0;


        //bfs
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            int row=node.first.first;
            int col=node.first.second;
            int newTime=node.second;
            time=max(time,newTime);

            for(int i=0;i<4;i++){
                int nrow=row+dx[i];
                int ncol=col+dy[i];

                if(nrow>=0 and nrow<m and ncol>=0 and ncol<n and grid[nrow][ncol]==1 and vis[nrow][ncol]==0){
                    grid[nrow][ncol]=2;
                    vis[nrow][ncol]=1;
                    q.push({{nrow,ncol},time+1});
                }
            }
        }


        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) return -1;
            }
        }

        return time;

    }
};