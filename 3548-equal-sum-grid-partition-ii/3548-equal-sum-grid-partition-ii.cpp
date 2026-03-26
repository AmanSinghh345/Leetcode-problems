
class Solution {
public:
    bool check(vector<vector<int>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        long long  total=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) total+=grid[i][j];
        }
        set<long long> st;
        long long top=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                top+=grid[i][j];
                st.insert(grid[i][j]);
            }
            long long  bottom=total-top;
            if(top==bottom) return true;
            else {
                long long diff=top-bottom;
                if(diff==grid[0][0] or diff==grid[0][m-1]) return true;
                if(diff==grid[i][0]) return true;
                if(i>0 and m>1 and st.find(diff)!=st.end()) return true;  
            }
        }
        return false;
    }
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        if(check(grid)) return true;
        reverse(begin(grid),end(grid));
        if(check(grid)) return true;
        reverse(begin(grid),end(grid));
        vector<vector<int>> transpose(m,vector<int> (n));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) transpose[j][i]=grid[i][j];
        }
        if(check(transpose)) return true;
        reverse(begin(transpose),end(transpose));
        if(check(transpose)) return true;
        return false;
    }
};