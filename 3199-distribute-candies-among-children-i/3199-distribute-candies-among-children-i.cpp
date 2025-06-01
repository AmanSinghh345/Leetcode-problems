class Solution {
public:
    int distributeCandies(int n, int limit) {
        int cnt=0;
        for(int i=0;i<=min(limit,n);i++){
            for(int j=0;j<=min(limit,n-i);j++){
                int k=n-i-j;
                if(i+j+k==n and k<=limit){ cnt++;}
            }
        }
        return cnt;
    }
};