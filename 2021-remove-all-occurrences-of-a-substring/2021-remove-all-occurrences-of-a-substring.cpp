class Solution {
public:
    string removeOccurrences(string s, string part) {
        int n=s.size();
        string S=s;
        int m=part.size();
        int i=0;
        while(i<S.size()){
            if(part==S.substr(i,m)) {
                S.erase(i,m);
                i=0;
            }
            else
            i++;
            
        }
        return S;
    }
};