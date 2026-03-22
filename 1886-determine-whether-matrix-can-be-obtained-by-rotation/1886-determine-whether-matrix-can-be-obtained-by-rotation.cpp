class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        // first i,j > j,M-i-1
        // second i,j > M-i-1,N-j-1
        // third i,j > N-j-1, i
        // fourth i,j> i,j
        bool f=true,s=true,t=true,fo=true;
        int m=mat.size();
        int n=mat[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){

                if(mat[i][j]!=target[i][j]) fo=false;
                if(mat[j][m-i-1]!=target[i][j]) f=false;
                if(mat[m-i-1][n-j-1]!=target[i][j]) s=false;
                if(mat[n-j-1][i]!=target[i][j]) t=false;
            }
        }
        if(fo || f || s|| t) return true;
        return false;
    }
};