class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        int total=m*n;
        vector<vector<int>> ans(m,vector<int>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int pos=i*n+j;
                int new_pos=(pos+k)%total;
                int ni=new_pos/n;
                int nj=new_pos%n;
                ans[ni][nj]=grid[i][j];
            }
        }
        return ans;
    }
};