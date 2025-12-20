class Solution {
public:
    long long lastInteger(long long n) {
        long long a=1,d=1;
        long long step=0;
        while(true)
        {
            long long len=1+((n-a)/d);
            if(len==1) break;
            if(step%2==1 and len%2==0) a=a+d;
            d*=2;
            step++;
        }   
        return a;
    }
};