class Solution {
public:
    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries) {
        int n=chunks.size();
        string s="";
        for(int i=0;i<n;i++) s+=chunks[i];

        unordered_map<string,int> umap;

        bool start=true;
        string valid="";
        for(int i=0;i<(int)s.size();i++){
            if(start){
                if(s[i]==' ' || s[i]=='-'){
                    continue;
                }
                else{
                    valid+=s[i];
                    start=false;
                }
            }
            else{
                if(s[i]!='-' && s[i]!=' '){
                    valid+=s[i];
                }
                else {
                    if(s[i]==' '){
                        umap[valid]++;
                        valid="";
                        start=true;
                    }
                    else{
                        if(s[i]=='-'){
                            if(i+1<(int)s.size() && s[i+1]!='-' && s[i+1]!=' '){
                                valid+=s[i];
                            }
                            else{
                                umap[valid]++;
                                valid="";
                                start=true;
                            }
                        }
                    }
                }
            }
        }

        if(!valid.empty()) umap[valid]++;

        int m=queries.size();
        vector<int> ans(m);
        for(int i=0;i<m;i++){
            if(umap.find(queries[i])!=umap.end())
            ans[i]=umap[queries[i]];
        }
        return ans;
    }
};