class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        
        for(int i=0;i<(n+2-1)/2;i++){
            for(int j=i;j<n-(i+1);j++){
                int pi=i,pj=j;
                int ni=j,nj=n-i-1;
                int prev=matrix[i][j];
                for(int k=0;k<4;k++){
                    int curr=matrix[ni][nj];
                    matrix[ni][nj]=prev;
                    
                    prev=curr;
                
                    pi=ni;
                    pj=nj;
                    ni=pj;
                    nj=n-pi-1;
                }
                   
            }
        }
        
    }
};