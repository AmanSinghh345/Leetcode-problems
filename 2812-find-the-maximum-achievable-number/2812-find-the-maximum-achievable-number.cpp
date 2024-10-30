class Solution {
public:
    int theMaximumAchievableX(int num, int t) {
        while(t--){
            num+=2;
        }
        return num;
    }
};