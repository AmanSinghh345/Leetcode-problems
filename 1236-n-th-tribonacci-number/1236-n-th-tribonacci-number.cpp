class Solution {
public:
    int tribonacci(int n) {
        if(n==2 || n==1) return 1;
        if(n==0) return 0;
        int prev=1;
        int prev2=1;
        int prev3=0;
        for(int i=3;i<=n;i++){
            int curi=prev+prev2+prev3;
            prev3=prev2;
            prev2=prev;
            prev=curi;
        }
        return prev;
    }
};