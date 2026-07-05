class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n=board.size();
        int mod=1e9+7;
        vector<vector<int>> score(n,vector<int>(n,-1));
        vector<vector<int>> ways(n,vector<int>(n,0));
        score[n-1][n-1]=0;
        ways[n-1][n-1]=1;
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(board[i][j]=='X') continue;
                if(i==n-1 and j==n-1) continue;
                int best=-1;
                int cnt=0;
            vector<pair<int,int>> pref={{i+1,j},{i+1,j+1},{i,j+1}};

                 for(auto [x,y]:pref){
                    if(x>=n or y>=n) continue;
                    if(score[x][y]==-1) continue;
                    if(score[x][y]>best) {
                        best=score[x][y];
                        cnt=ways[x][y];
                    }
                    else if(score[x][y]==best){
                        cnt=(cnt+ways[x][y])%mod;
                    }
                 }
                 if(best==-1) continue;

                 if(board[i][j]=='S' or board[i][j]=='E') best+=0;
                 else best+=(board[i][j]-'0');
                 score[i][j]=best;
                 ways[i][j]=cnt;
            }
        }
        if(score[0][0]==-1) return {0,0};
        return {score[0][0],ways[0][0]};
    }
};