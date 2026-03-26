class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<long long> rowPref(m+1,0);
         long long  total=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
            
                total+=grid[i][j];
            }
            rowPref[i+1]=total;
        }

        if(total&1) return false;
        long long  req=total/2;
        for(int i=1;i<=m;i++) {
            if(rowPref[i]==req) return true;
        }
        vector<long long> colPref(n+1,0);
        long long curr=0;
        for(int j=0;j<n;j++){
            for(int i=0;i<m;i++){
                curr+=grid[i][j];
            }
            colPref[j+1]=curr;
            if(curr==req) return true;
        }
        return false;
    }
};