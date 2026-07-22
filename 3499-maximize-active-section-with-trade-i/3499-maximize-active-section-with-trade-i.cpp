class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n=s.size();
        int ans=0;
        for(char c:s) {
            if(c=='1') ans++;
        }

        int prev=INT_MIN;
        int curr=0;
        int maxi=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                int j=i+1;
                while(j<n && s[j]==s[i]){
                    j++;
                  
                }
                curr=j-i;
        
                maxi=max(maxi,prev+curr);
                prev=curr;
                i=j;
                continue;
            }
          
        }
        cout<<ans<<" "<<maxi<<endl;
        return ans+maxi;
    }
};