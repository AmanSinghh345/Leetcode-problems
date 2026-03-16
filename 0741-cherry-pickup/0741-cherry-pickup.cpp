class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();  
        vector<vector<int>> prev(n,vector<int> (n,INT_MIN));
        prev[0][0]=grid[0][0];
        for(int t=1;t<=2*n-2;t++){
            vector<vector<int>> curr(n,vector<int>(n,INT_MIN));
            for(int r1=max(0,t-(n-1));r1<=min(n-1,t);r1++){
                for(int r2=max(0,t-(n-1));r2<=min(n-1,t);r2++){
                    int c1=t-r1;
                    int c2=t-r2;

                    if(grid[r1][c1]==-1 or grid[r2][c2]==-1) continue;
                    int cnt=(r1==r2)?grid[r1][c1]:(grid[r1][c1]+grid[r2][c2]);

                    int best=prev[r1][r2];
                    if(r1>0) best=max(best,prev[r1-1][r2]);
                    if(r2>0) best=max(best,prev[r1][r2-1]);
                    if(r1>0 and r2>0) best=max(best,prev[r1-1][r2-1]);
                    curr[r1][r2]=cnt+best;
                }
            }
            prev=curr;
        }
        return max(prev[n-1][n-1],0);
    }
};