class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> mp;
        int n=s.size();
        int l=0;
        int ans=0;
        for(int r=0;r<n;r++)
        {
            if(mp.find(s[r])!=mp.end())
            {
                if(mp[s[r]]>=l) {
                    l=mp[s[r]]+1;
                }
            }
            ans=max(ans,r-l+1);
            mp[s[r]]=r;
        }
        return ans;
    }
};