class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> last(256,-1);
        int n=s.size();
        int l=0;
        int ans=0;
        for(int r=0;r<n;r++)
        {
            
                if(last[s[r]]>=l) {
                    l=last[s[r]]+1;
                }
            
            ans=max(ans,r-l+1);
            last[s[r]]=r;
        }
        return ans;
    }
};