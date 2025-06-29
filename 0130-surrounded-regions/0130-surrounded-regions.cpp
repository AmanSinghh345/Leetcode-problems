class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();

        queue<pair<int,int>> q; // to store the starting position i.e coordinate of outer edge having O
        vector<vector<int>> vis(m,vector<int> (n,0)); // to check it the cell is visited or not
        //Starting position
        // first row
        int row=0;
        for(int col=0;col<n;col++){
            if(board[row][col]=='O'){
                q.push({row,col});
                vis[row][col]=1;
            }
        }
        //last row
        row=m-1;
        for(int col=0;col<n;col++){
            if(board[row][col]=='O'){
                q.push({row,col});
                vis[row][col]=1;
            }
        }
        //First col
        int col=0;
        for(int row=1;row<m-1;row++){
            if(board[row][col]=='O'){
                q.push({row,col});
                vis[row][col]=1;
            }
        }
        //Last col
         col=n-1;
         for(int row=1;row<m-1;row++){
            if(board[row][col]=='O'){
                q.push({row,col});
                vis[row][col]=1;
            }
         }
        
        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            int row=node.first;
            int col=node.second;
            for(int i=0;i<4;i++){
                int nrow=row+dx[i];
                int ncol=col+dy[i];
                if(nrow>=0 and nrow<m and ncol>=0 and ncol<n and vis[nrow][ncol]==0 and board[nrow][ncol]=='O'){
                    q.push({nrow,ncol});
                    vis[nrow][ncol]=1;
                }
            }
        }
        //the cell we havnt visited are surrounded by X and are not connected with O present at edge
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O' and vis[i][j]==0){
                    board[i][j]='X';
                }
            }
        }

    }
};