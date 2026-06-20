class Solution {
public:
    bool checkGoodInteger(int n) {
        long long  squareSum=0;
        long long digitSum=0;
        while(n>0){
            int ld=n%10;
            n/=10;
            digitSum+=ld;
            squareSum+=(ld*ld);
        }
        return (squareSum-digitSum)>=50;
    }
};