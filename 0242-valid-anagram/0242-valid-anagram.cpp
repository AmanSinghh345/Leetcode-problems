class Solution {
public:
    bool isAnagram(string s, string t) {
        int n=s.size();
        int m=t.size();
        if(n!=m) return false;
        unordered_map<char,int> u1,u2;
        for(int i=0;i<n;i++)
        {
            u1[s[i]]++;
            u2[t[i]]++;
        }
        for(auto it=u1.begin();it!=u1.end();it++)
        {
            if(it->second!=u2[it->first]) return false;
        }
        return true;
    }
};