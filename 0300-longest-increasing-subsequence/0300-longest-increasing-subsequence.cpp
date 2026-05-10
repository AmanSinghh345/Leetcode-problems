class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        vector<int> dp ;
        for(auto it : nums){
            if(dp.size()==0 || dp.back()<it){
                dp.push_back(it);
            }
            else{
                auto iit=lower_bound(dp.begin(),dp.end(),it);
                *iit=it;
            }
        }
        return dp.size();
    }
};