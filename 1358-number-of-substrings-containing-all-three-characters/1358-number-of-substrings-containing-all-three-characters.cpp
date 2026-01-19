class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        long long totalSubstrings=(1LL*n*(n+1))/2;
        return totalSubstrings-atmost(s,2);
    }
    int atmost(string s,int k)
    {
        int n=s.size();
        int l=0;
        unordered_map<char,int> freq;
        int cnt=0;
        for(int r=0;r<n;r++)
        {
            freq[s[r]]++;
            while(l<n and freq.size()>k)
            {
                freq[s[l]]--;
                if(freq[s[l]]==0) freq.erase(s[l]);
                l++;
            }
            cnt+=(r-l+1);
        }
        return cnt;
    }
};