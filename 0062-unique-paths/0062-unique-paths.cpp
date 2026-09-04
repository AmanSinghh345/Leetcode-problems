class Solution {
public:
    long long nCr(int n,int r){
        long long res=1;
        for(int i=1;i<=r;i++){
            res=(res*(n-r+i))/i;
        }
        return res;
    }
    int uniquePaths(int m, int n) {
        return nCr(m+n-2,m-1);
    }
};