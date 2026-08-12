class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        unordered_map<char,int> umap;
        int l=0;
        int ans=0;
        for(int r=0;r<n;r++){
            umap[s[r]]++;
            while(umap[s[r]]>1) {
                umap[s[l]]--;
                l++;
            }
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};