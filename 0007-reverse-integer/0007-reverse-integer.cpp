class Solution {
public:
    int reverse(int x) {
       long long ans=0;
       bool pos=true;
       long long temp=x;
       if(temp<0){
            pos=false;
            temp=temp*(-1);
       }
       
       while(temp>0){
        int ld=temp%10;
        ans=(long long)ans*10 + ld;
        temp/=10;
       }
       if(ans>INT_MAX and pos) return 0;
       if(ans>(long long)-1*INT_MIN and pos==false) return 0; 

        return pos?ans:(-1)*ans;
    }
};