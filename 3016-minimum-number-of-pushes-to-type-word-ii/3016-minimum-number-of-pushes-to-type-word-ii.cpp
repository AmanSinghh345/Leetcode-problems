class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();
        vector<int> freq(26,0);
        for(char & c: word) freq[c-'a']++;
        vector<pair<int,int>> arr;
        for(int i=0;i<26;i++){
            arr.push_back({freq[i],i});
        }
        sort(arr.rbegin(),arr.rend());
        int cnt=0;
        for(int i=0;i<26;i++){
            cnt+=(i/8+1)*(arr[i].first);
        }
        return cnt;
    }
};