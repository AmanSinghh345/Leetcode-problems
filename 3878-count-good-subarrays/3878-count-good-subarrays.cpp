class Solution {
public:
    long long countGoodSubarrays(vector<int>& nums) {
        int n=nums.size();

        vector<int> L(n),R(n);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() and nums[st.top()]<nums[i]) st.pop();
        
            if(st.empty()) L[i]=0;
            else L[i]=st.top()+1;
            st.push(i);

        }
        while(!st.empty()) st.pop();

        for(int i=n-1;i>=0;i--){
            while(!st.empty() and nums[st.top()]<=nums[i]) st.pop();

            if(st.empty()) R[i]=n-1;
            else R[i]=st.top()-1;
            st.push(i);
        }

        vector<vector<int>> prev(n,vector<int> (32,-1));
        vector<vector<int>> next(n,vector<int> (32,-1));
        vector<int> last(32,-1);

        for(int i=0;i<n;i++){

            for(int b=0;b<32;b++){
                prev[i][b]=last[b];
            }
            for(int b=0;b<32;b++){
                if(nums[i]&(1<<b)) last[b]=i;
            }
        }

        fill(last.begin(),last.end(),n);

        for(int i=n-1;i>=0;i--){
            for(int b=0;b<32;b++){
                next[i][b]=last[b];
            }
            for(int b=0;b<32;b++){
                if(nums[i]&(1<<b)) last[b]=i;
            }
        }

        long long ans=0;
        for(int i=0;i<n;i++){
            int l=L[i],r=R[i];

            for(int b=0;b<32;b++){
                if(!(nums[i]&(1<<b))){
                    l=max(l,prev[i][b]+1);
                    r=min(r,next[i][b]-1);
                }
               
            }
             if(l<=r)
                ans+=1LL*(i-l+1)*(r-i+1);
        }
        return ans;
     }
};