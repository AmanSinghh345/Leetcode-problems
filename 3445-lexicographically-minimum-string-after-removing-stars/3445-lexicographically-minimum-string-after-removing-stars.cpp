class Solution {
public:
    string clearStars(string s) {
        int n=s.size();
        //list of list 
        vector<vector<int>> arr(26);
        for(int i=0;i<n;i++){
            if(s[i]!='*'){
                arr[s[i]-'a'].push_back(i);
            }
            else{
                for(int i=0;i<26;i++){
                    if(arr[i].size()>0){
                        s[arr[i].back()]='*';
                        arr[i].pop_back();
                        break;
                    }
                }
            }
        }
        string ans="";
        for(int i=0;i<n;i++){
            if(s[i]=='*') continue;
            ans+=s[i];
        }
        return ans;
    }
};