class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> need,window;
        for(char c:t)  need[c]++;
        int start=0;
        int minLen=INT_MAX;
        int l=0;
        int formed=0;
        int req=need.size();
        for(int r=0;r<s.size();r++){
            char c=s[r];
            window[c]++;
            if(need.count(c) && need[c]==window[c]) formed++;
            while(req==formed){
                if(r-l+1<minLen){
                    minLen=r-l+1;
                    start=l;
                }
                window[s[l]]--;
                if(need.count(s[l]) && need[s[l]]>window[s[l]]){
                    formed--;
                }
                l++;
            }
        }
        return minLen==INT_MAX?"":s.substr(start,minLen);
    }
};