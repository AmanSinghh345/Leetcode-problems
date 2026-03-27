class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m=mat.size();
        int n=mat[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int ni=i;
                 int nj;
                if(i&1) {
                    nj=(j+k)%n;
                }
                else nj=(j+n-k%n)%n;
               
                if(mat[i][j]!=mat[ni][nj]) return false;
            }
        }
        return true;
    }
};