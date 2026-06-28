class Solution {
public:
    int generateKey(int num1, int num2, int num3) {
        int ans=0;
        int place=1;
        for(int i=0;i<4;i++){
            ans+=(min({num1/place % 10  , num2/place % 10 , num3/place % 10 }))*place;
            place*=10;
        }
        return ans;
    }
};