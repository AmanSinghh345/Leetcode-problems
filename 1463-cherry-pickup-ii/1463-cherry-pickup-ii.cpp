class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> prev(n,vector<int> (n,INT_MIN));
        
        prev[0][n-1]=grid[0][0]+grid[0][n-1];

        for(int i=1;i<m;i++){
            vector<vector<int>> curr(n,vector<int> (n,INT_MIN));
            for(int c1=0;c1<n;c1++){
                for(int c2=0;c2<n;c2++){
                    int cnt=(c1==c2)?grid[i][c1]:grid[i][c1]+grid[i][c2];
                    int best=INT_MIN;
                    for(int k=-1;k<=1;k++){
                        for(int l=-1;l<=1;l++){
                            int nc1=c1+k;
                            int nc2=c2+l;
                            if(nc1>=0 and nc1<n and nc2>=0 and nc2<n) {
                                best=max(best,prev[nc1][nc2]);
                            }
                        }
                    }
                    if(best!=INT_MIN)
                    curr[c1][c2]=cnt+best;
                }
            }
            prev=curr;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ans=max(ans,prev[i][j]);
            }
        }
        return ans;

    }
};