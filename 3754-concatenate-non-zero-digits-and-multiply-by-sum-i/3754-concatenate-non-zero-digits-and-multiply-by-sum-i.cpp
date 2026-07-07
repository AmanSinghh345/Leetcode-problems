class Solution {
public:
    long long sumAndMultiply(int n) {
        string s="";
        long long sum=0;
        while(n>0){
            int ld=n%10;
             n/=10;
            if(ld==0) continue;
            char c=ld+'0';

            s=c+s;
            sum+=ld;
        }
        if(s.empty()) return 0;
        long long x=stoll(s);
        return x*sum;
    }
};