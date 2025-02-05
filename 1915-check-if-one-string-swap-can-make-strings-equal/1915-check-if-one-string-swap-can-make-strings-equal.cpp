class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n=s1.size();
        int cnt=0;
        string  d;
        string f;
        for(int i=0;i<n;i++){
            if(s1[i]!=s2[i]) {
                 cnt++;
                d.push_back(s1[i]);
                f.push_back(s2[i]);
            }
            
            if(cnt>2) return false;
        }
        if(d[0]==f[1] && d[1]==f[0]) return true;
        return false;
    }
};