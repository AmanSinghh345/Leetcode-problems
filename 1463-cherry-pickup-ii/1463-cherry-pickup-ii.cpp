class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> prev(n,vector<int> (n,-1));
        prev[0][n-1]=grid[0][0]+grid[0][n-1];
        for(int i=1;i<m;i++){
            vector<vector<int>> curr(n,vector<int> (n,0));
        
            for(int c1=0;c1<n;c1++){
                for(int c2=0;c2<n;c2++){
                    curr[c1][c2]=(c1==c2)?grid[i][c1]:grid[i][c1]+grid[i][c2];
                    int best=-1;
                    for(int k=-1;k<2;k++){
                        for(int l=-1;l<2;l++){
                            int nc1=c1+k;
                            int nc2=c2+l;
                            if(nc1>=0 && nc1<n && nc2>=0 && nc2<n && prev[nc1][nc2]!=-1){
                                best=max(best,prev[nc1][nc2]);
                            }
                        }
                    }
                    if(best==-1) curr[c1][c2]=-1;
                    else
                    curr[c1][c2]+=best;
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