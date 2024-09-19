class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n=words.size();
        int count=0;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
            int m=words[i].size();
            if(words[i]==words[j].substr(0,m) && words[i]==words[j].substr(words[j].size()-m))
            count++;
        }
        }
        return count;
    }
};