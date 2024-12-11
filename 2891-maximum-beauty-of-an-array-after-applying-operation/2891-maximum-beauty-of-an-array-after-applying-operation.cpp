class Solution {
    #define pii pair<int,int>
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int max_count=0;
        int cnt=0;
        int left=0,right=0;
        int n=nums.size();
        while(right<n){
            while(right<n and (nums[right]-nums[left])<=2*k){
                cnt++;
                right++;
            }
            
            max_count = max(max_count,cnt);
            if(right==n) break;

            while(left<=right and (nums[right]-nums[left])>2*k){
                cnt--;
                left++;
            }
        }
        return max_count;
    }
};