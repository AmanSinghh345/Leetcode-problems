class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<long long> prefix(n+1,0);
        deque<int> deque;
        int ans=n+1;
        for(int i=0;i<n;i++){
            prefix[i+1]=nums[i]+prefix[i];
        }
        for(int i=0;i<=n;i++){
            while(!deque.empty() and prefix[i]-prefix[deque.front()]>=k){
                ans=min(ans,i-deque.front());
                deque.pop_front();
            }
            while(!deque.empty() and prefix[i]<=prefix[deque.back()]){
                deque.pop_back();
            }
            deque.push_back(i);
        }
        return ans==n+1?-1:ans;
    }
};