class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        int l=0,r=0,ans=0;
        unordered_map<char,int> umap;
        while(r<n){
            umap[s[r]]++;
            while(umap.size()==3){
                ans+=n-r;
                umap[s[l]]--;
                if(umap[s[l]]==0) umap.erase(s[l]);
                l++;
            }
            r++;
        }
        return ans;
    }
};