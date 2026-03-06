class Solution {
public:
    bool checkOnesSegment(string s) {
        int n=s.size();
        int cntOne=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='1') cntOne++;
        }
        int seg=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='1') seg++;
            else break;
        }
        if(seg==cntOne) return true;
        return false;
    }
};