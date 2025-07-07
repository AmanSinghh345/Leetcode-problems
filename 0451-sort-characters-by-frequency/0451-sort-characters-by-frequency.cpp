class Solution {
public:
    string frequencySort(string s) {
        int n=s.size();
        map<char,int> map;
        for(auto& it:s){       //O(n)
            map[it]++;
        }
        multimap<int,char,greater<int>> mmap;
        for(auto& it:map){       //    O(mlog(m)) m is number of unique character
            mmap.insert({it.second,it.first});
        }
        string ans="";
        for(auto& it:mmap){         // O(mlog(m))
            ans+=string(it.first,it.second);
        }
        return ans;

        // tc : O(n + mlog(m)) sc : O(n)
    }
};