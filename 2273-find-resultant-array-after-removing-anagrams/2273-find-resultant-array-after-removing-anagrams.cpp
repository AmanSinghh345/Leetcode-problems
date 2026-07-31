class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
   
        string currKey="";
        for(string& s:words){
            string key="";
            vector<int> freq(26,0);
            for(char & c:s) freq[c-'a']++;
            for(int i=0;i<26;i++) key=key+"#"+to_string(freq[i]);
            if(currKey==key) continue;
            else {
                currKey=key;
                ans.push_back(s);
            }
           
        }
        return ans;
    }
};