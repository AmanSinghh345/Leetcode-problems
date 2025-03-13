class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        set<int> s1(nums1.begin(),nums1.end());
        set<int> s2(nums2.begin(),nums2.end());
        vector<vector<int>> ans(2);
        for(auto it=s1.begin();it!=s1.end();it++){
            if(s2.find(*it)!=s2.end()) continue;
            else ans[0].push_back(*it);
        }
        for(auto it=s2.begin();it!=s2.end();it++){
            if(s1.find(*it)!=s1.end()) continue;
            else ans[1].push_back(*it);
        }
        return ans;
    }
};