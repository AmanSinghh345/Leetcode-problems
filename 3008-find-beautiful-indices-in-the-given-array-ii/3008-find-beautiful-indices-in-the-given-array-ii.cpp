class Solution {
public:
    vector<int> kmp(string s){
        int n=s.size();
        vector<int> lps(n,0);
        for(int i=1;i<n;i++){
            int prev_ind=lps[i-1];
            while(prev_ind>0 and s[i]!=s[prev_ind]){
                prev_ind=lps[prev_ind-1];
            }
            if(s[i]==s[prev_ind]) prev_ind++;
            lps[i]=prev_ind;
        }
        return lps;
    }
    vector<int> beautifulIndices(string s, string a, string b, int k) {

        string f=a+"#"+s;
        string sec=b+"#"+s;
        vector<int> first=kmp(f);
        vector<int> startingForFirst;
        for(int i=(2*a.size());i<first.size();i++){
            if(first[i]==a.size()) {
                startingForFirst.push_back(i-2*a.size());
            }
        }
        vector<int> second=kmp(sec);
        vector<int> startingForSecond;
        for(int j=(2*b.size());j<second.size();j++){
            if(second[j]==b.size()){
                startingForSecond.push_back(j-2*b.size());
            }
        }
        vector<int> valid;
        for(int i=0;i<startingForFirst.size();i++){
            auto lb=lower_bound(startingForSecond.begin(),startingForSecond.end(),startingForFirst[i]);
            
            if(lb!=startingForSecond.end() and abs(*lb-startingForFirst[i])<=k){
                valid.push_back(startingForFirst[i]);
            }
            else if(lb!=startingForSecond.begin()){
                lb--;
            if(abs(*lb-startingForFirst[i])<=k) valid.push_back(startingForFirst[i]);
        }
        }
        return valid;
    }
};