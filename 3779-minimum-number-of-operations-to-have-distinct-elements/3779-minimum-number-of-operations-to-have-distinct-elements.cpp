class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int i=n-1;
        set<int> st;
        int cnt=0;
        for(int i=n-1;i>=0;i--)
            {
                if(st.find(nums[i])==st.end())
                {
                    st.insert(nums[i]);
                }
                else
                {
                    break;
                }
                cnt++;
            }
        cnt=n-cnt;
        int ans=(cnt+3-1)/3;
        return ans;
    }
};