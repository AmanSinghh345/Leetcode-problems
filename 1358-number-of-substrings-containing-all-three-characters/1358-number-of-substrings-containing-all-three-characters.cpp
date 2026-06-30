class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char,int> umap;
        int n=s.size();
        int l=0;
        int cnt=0;
        for(int r=0;r<n;r++){
             umap[s[r]]++;
            while(l<r && umap.size()==3){
                cnt+=(n-r);
                umap[s[l]]--;
                if(umap[s[l]]==0) umap.erase(s[l]);
                l++;
            }
        }
        return cnt;
    }
};