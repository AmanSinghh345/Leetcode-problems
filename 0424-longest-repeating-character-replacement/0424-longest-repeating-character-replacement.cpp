class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> umap;
        int n=s.size();
        int ans=0;
        int l=0;
        int maxFreq=0;
        for(int r=0;r<n;r++)
        {
            umap[s[r]]++;
            maxFreq=max(maxFreq,umap[s[r]]);
            int len=r-l+1;
            int req=len-maxFreq;
            if(req<=k) ans=max(ans,len);
            else {
                umap[s[l]]--;
                l++;
            }
        }
        return ans;
    }
};