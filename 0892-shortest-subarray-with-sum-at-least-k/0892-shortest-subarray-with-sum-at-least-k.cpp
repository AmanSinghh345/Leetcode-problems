class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        int mini=INT_MAX;
       bool flag=true;
       vector<long> prefix(n+1,0);
            for(int i=0;i<n;i++){
           prefix[i+1]=prefix[i]+nums[i];
        }
        deque<int> dq;
        for(int i=0;i<=n;i++){
            while(!dq.empty() && prefix[i]-prefix[dq.front()]>=k){
                mini=min(mini,i-dq.front());
                flag=false;
                dq.pop_front();
            }
            while(!dq.empty()&& prefix[i]<=prefix[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        if(flag) return -1;
        else 
        return mini;
    }
};