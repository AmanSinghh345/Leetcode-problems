class Solution {
public:
    int maxProduct(int n) {
        string s=to_string(n);
        sort(s.rbegin(),s.rend());
        if(s.size()==1) return s[0]-'0';
        return (s[0]-'0')*(s[1]-'0');
    }
};