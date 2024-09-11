class Solution {
public:
    bool checkString(string s) {
        int n=s.size();
        int flag=1;
        for(int i=0;i<n;i++){
            if(s[i]=='b'&& s[i+1]=='a')
            {
                      flag=0;
            }
        }
        return flag==1;
            }
};