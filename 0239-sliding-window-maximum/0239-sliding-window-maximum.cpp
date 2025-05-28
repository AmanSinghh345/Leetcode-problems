class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        
        vector<int> ans;
        set<pair<int,int>> st;

        //First Window
        for(int i=0;i<k;++i){
            st.insert({nums[i],i});
        }

        ans.push_back(prev(st.end())->first);

        for(int i=k;i<n;i++){
            st.insert({nums[i],i});
            st.erase({nums[i-k],i-k});
            ans.push_back(prev(st.end())->first);
        }
        return ans;
    }
};