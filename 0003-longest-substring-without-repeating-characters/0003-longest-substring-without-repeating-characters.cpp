class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int hash[256];
            memset(hash,0,sizeof(hash));
            for(int j=i;j<n;j++)
            {
                if(hash[s[j]]==1) break;
                ans=max(ans,j-i+1);
                hash[s[j]]=1;
            }
        }
        return ans;
    }
};