const int mod=1e9+7;
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        stack<int> st;
        vector<int> pse(n),nse(n);
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            if(st.empty()) pse[i]=-1;
            else pse[i]=st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]) {st.pop();}
            if(st.empty()) nse[i]=n;
            else nse[i]=st.top();
            st.push(i);
        }

        int ans=0;
        for(int i=0;i<n;i++){
            int left=i-pse[i];
            int right=nse[i]-i;
            ans=(ans+((1LL*left*right)%mod)*1LL*arr[i])%mod;
            
        }
        return ans;
    }
};