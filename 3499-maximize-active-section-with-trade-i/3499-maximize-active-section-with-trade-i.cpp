class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int ans=0;
        for(char c:s) {
            if(c=='1') ans++;
        }
        int n=s.size();
        int maxi=0,prev=INT_MIN;
        int curr=0;
        int i=0;
        while(i<n){
            if(s[i]=='0'){
            int j=i+1;
            while(j<n && s[i]==s[j]){
                j++;
            }
            curr=j-i;
            maxi=max(maxi,curr+prev);
            prev=curr;
            i=j;
            continue;
            }
            i++;

        }
        ans+=maxi;
        return ans;
    }
};