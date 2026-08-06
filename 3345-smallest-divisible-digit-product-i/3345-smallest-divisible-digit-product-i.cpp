class Solution {
public:
    int smallestNumber(int n, int t) {
        while(true){
            int num=n;
            int prod=1;
            while(num>0){
                int ld=num%10;
                num/=10;
                prod*=ld;
            }
            if(prod%t==0) return n;
            n++;
        }
        return -1;
    }
};