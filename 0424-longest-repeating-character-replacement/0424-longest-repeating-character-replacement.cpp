class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        unordered_map<char,int> umap;
        int l=0;
        int curMax=0;
        int ans=0;
        for(int r=0;r<n;r++)
        {
            umap[s[r]]++;
            curMax=max(curMax,umap[s[r]]);
        
            while((r-l+1)-curMax>k)
            {
                umap[s[l]]--;
                l++;
            }
            ans=max(ans,r-l+1);


        }
        return ans;
    }
};