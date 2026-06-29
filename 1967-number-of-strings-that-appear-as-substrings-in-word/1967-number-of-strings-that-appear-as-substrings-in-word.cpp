class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        unordered_map<string,int> umap;

        int n=word.size();
        for(int i=0;i<n;i++){
            string s="";
            for(int j=i;j<n;j++){
                s+=word[j];
                umap[s]++;
            }
        }
        int cnt=0;
        for(string s:patterns){
            if(umap.count(s)) cnt++;
        }
        return cnt;
    }
};