class Solution {
public:
    double myPow(double x, int n) {
        if(x==1) return 1;
        double ans=1;
        bool sign=true;
        if(n<0) sign=false;

        long long z=abs((long long )n);
        while(z!=0){
            if(z&1==1){
                ans=ans*x;
                z=z-1;
            }
            else {
                x=x*x;
                z=z/2;
            }

        }


        if(!sign) return (double)1/ans;
        return ans;
    }
};