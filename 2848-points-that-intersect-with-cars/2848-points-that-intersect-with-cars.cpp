class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        vector<int> prefix(102,0);
        for(auto num:nums){
            prefix[num[0]]++;
            prefix[num[1]+1]--;
        }
        int pref=0;
        int cnt=0;
        for(int x:prefix){
            pref+=x;
            if(pref>0) cnt++;
        }
        return cnt;
    }
};