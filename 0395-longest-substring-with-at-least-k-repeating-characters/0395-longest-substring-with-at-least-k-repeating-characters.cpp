class Solution {
public:
    int find(int l,int r,string& s,int k){
        if(r-l+1<k) return 0;
        vector<int> freq(26,0);
        for(int i=l;i<=r;i++) freq[s[i]-'a']++;

        for(int i=l;i<=r;i++){
            if(freq[s[i]-'a']<k){
                int left=find(l,i-1,s,k);
                int right=find(i+1,r,s,k);
                return max(left,right);
            }
        }
        return r-l+1;
    }
    int longestSubstring(string s, int k) {
        return find(0,s.size()-1,s,k);
    }
};