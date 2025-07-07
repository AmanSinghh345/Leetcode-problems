class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> umap;
        int n=s.size();
        int maxfreq=0;
        for(auto c: s){             //O(n)
            umap[c]++;
            maxfreq=max(maxfreq,umap[c]);
        }

        //create a bucket
        vector<vector<char>> bucket(maxfreq+1);      
        for(auto& [ch,f]: umap){        //O(m)
            bucket[f].push_back(ch);
        }
        string ans="";
        for(int i=maxfreq;i>=0;i--){        //O(n)
            for(int j=0;j<bucket[i].size();j++){
                ans+=string(i,bucket[i][j]);
            }
        }
        return ans;
    }
    // tc O(n) sc O(n)
};