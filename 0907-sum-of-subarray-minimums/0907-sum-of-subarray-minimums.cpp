const int mod=1e9+7;
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int> nse(n);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            if(st.empty()) {
                nse[i]=-1;
                
            }
            else{
                nse[i]=st.top();
            }
            st.push(i);
        }
         int ans=0;
        for(int i=0;i<n;i++){
            
            int j=i;
       
            int contribute;
            while(j<n){
                if(nse[j]==-1){
                 contribute=(n-j)*arr[j];
                    ans=(ans+contribute)%mod;
                    break;
                }
                contribute=(nse[j]-j)*arr[j];
                ans=(ans+contribute)%mod;
                j=nse[j];
            }
        }
        return ans;
    }
};