class Solution {
public:
    int countDigitOne(int n) {
        if(n<=0) return 0;
        if(n<=9) return 1;
        int ans=0;
        unordered_map<int,int> mpp;
        mpp[9]=1;
        for(int i=9;i<(INT_MAX - 9)/10;i=10*i+9)
        mpp[10*i+9]=mpp[i]*10 + i+1;

        int temp=n;
        int divisor=1;
        while(temp/10){
            temp/=10;
            divisor*=10;
        }
        int first_digit=n/divisor;
        int rem=n%divisor;

        ans+=mpp[divisor-1]*first_digit;
        ans+=(first_digit>1)?divisor:0;
        ans+=(first_digit==1)?rem+1:0;
        ans+=countDigitOne(rem);
        return ans;
    }
};
/*        APPROACH :-
f(9) = 1
f(19) = 2*[0-9] +  [10-19]
    = 2*f(9) + 10
    = 2*1  +10
    = 12
f(26) = 2*[0,9] + [10-19] +[20-26]
=   2  + 10 +  f(6)
=  13
f(99) = 10*f(9) + 10 = 20
f(999) = 10*f(99) +100([100-199])= 200 +100 =300
f(3467) = 3*f(999) + 1000 + f(467)


*/