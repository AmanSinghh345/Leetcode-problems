class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0) return 1;
        int v=1;
        int ans=0;
        int cnt=1;
        while(v<n){
            if((n&v )==0) {
                ans=ans|v;
            }
            v<<=1;
            
        }
        return ans;
    }
};