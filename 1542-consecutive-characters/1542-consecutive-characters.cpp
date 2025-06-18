class Solution {
public:
    int maxPower(string s) {
        set<char> st;
        int l=0,r=0;
        int cnt=0;
        int n=s.size();
        while(r<n){
            st.insert(s[r]);
            if(st.size()>1){
                st.erase(s[r-1]);
                l=r;
            }
            cnt=max(cnt,r-l+1);
            r++;
        }
        return cnt;
    }
};