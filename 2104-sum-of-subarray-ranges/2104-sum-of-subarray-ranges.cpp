class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        vector<int> nge(n),pge(n),nse(n),pse(n);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]<nums[i]){
                st.pop();
            }
            if(st.empty()){
                pge[i]=-1;
            }
            else{
                pge[i]=st.top();
            }
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]<=nums[i]){
                st.pop();
            }
            if(st.empty()){
                nge[i]=n;
            }
            else nge[i]=st.top();
            st.push(i);
        }
         while(!st.empty()) st.pop();
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]>nums[i]){
                st.pop();

            }
            if(st.empty()) pse[i]=-1;
            else pse[i]=st.top();
            st.push(i);

        }
          while(!st.empty()) st.pop();
            for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]>=nums[i]){
                st.pop();

            }
            if(st.empty()) nse[i]=n;
            else nse[i]=st.top();
            st.push(i);

        }

        long long ans=0;
        for(int i=0;i<n;i++){

                //pos 
                int l1=i-pge[i];
                int r1=nge[i]-i;
                long long pos=((l1*1ll*r1)*nums[i]);

                //neg
                int l2=i-pse[i];
                int r2=nse[i]-i;
                long long neg=((l2*1ll*r2)*nums[i]);

                ans+=(pos-neg);
        }
        return ans;
    }
};