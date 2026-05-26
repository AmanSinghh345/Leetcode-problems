class Solution {
public:
    vector<vector<string>> res;
    unordered_map<string,vector<string>> parents;

    void dfs(string word,string beginWord,vector<string>& path){
            if(word==beginWord){
                vector<string> temp=path;
                reverse(temp.begin(),temp.end());
                res.push_back(temp);
                return ;
            }
            for(string& parent: parents[word]){
                path.push_back(parent);
                dfs(parent,beginWord,path);
                path.pop_back();
            }
            return;
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {


        unordered_set<string> wordSet(wordList.begin(),wordList.end());

        if(!wordSet.count(endWord)) return {};

        unordered_set<string> level;
        level.insert(beginWord);
        bool found=false;

        while(!level.empty() && !found){

            unordered_set<string> nextLevel;

            for(auto& word : level){
                wordSet.erase(word);
            }

            for(auto& word : level){
                string curr=word;
                for(int i=0;i<curr.size();i++){
                    char original=curr[i];

                    for( char ch='a';ch<='z';ch++){
                            curr[i]=ch;
                            if(wordSet.count(curr)){
                                if(curr==endWord) found = true;

                                nextLevel.insert(curr);
                                parents[curr].push_back(word);

                            }
                    }
                    curr[i]=original;
                }
               
            }
             level=nextLevel;
        }

        if(found){
            vector<string> path={endWord};
            dfs(endWord,beginWord,path);
        }
        return res;
    }
};