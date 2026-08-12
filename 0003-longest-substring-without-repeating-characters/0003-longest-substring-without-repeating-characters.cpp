class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        vector<int> freq(256,-1);
        int ans=0;
        int l=-1;
        for(int i=0;i<n;i++){
            if(freq[s[i]]>l){
                l=freq[s[i]];
            }
            ans=max(ans,i-l);
            freq[s[i]]=i;
        }
        return ans;
    }
};