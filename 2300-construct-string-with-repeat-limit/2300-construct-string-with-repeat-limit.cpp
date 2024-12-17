class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> freq(26,0);
        for(int i=0;i<s.size();i++){
            freq[s[i]-'a']++;

        }
        priority_queue<pair<int,int>> maxHeap;
        for(int i=0;i<26;i++){
            if(freq[i]>0) maxHeap.push(make_pair(i,freq[i]));
        }
        string ans;
        while(!maxHeap.empty()){
            pair<int,int> current=maxHeap.top();
            maxHeap.pop();
            char current_char='a'+current.first;
            int cnt=min(current.second,repeatLimit);
            current.second-=cnt;
            ans.append(cnt,current_char);
            if(current.second){
                if(maxHeap.empty()) break;
                pair<int,int> next=maxHeap.top();
                maxHeap.pop();
                char next_char='a'+next.first;

                ans.push_back(next_char);
                next.second--;
                if(next.second>0) maxHeap.push(next);
                maxHeap.push(current);
            }
        }
        return ans;
    }
};