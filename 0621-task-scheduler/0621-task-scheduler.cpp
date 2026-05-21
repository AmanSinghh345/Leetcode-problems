class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> freq;
        for(auto & c : tasks) freq[c]++;

        priority_queue<int> pq;
        for(auto& [c,d]:freq) pq.push(d);
        int time=0;
        while(!pq.empty()){
            vector<int> temp;
            int cycle=n+1;
            int i=0;
            while(i<cycle && !pq.empty()){
                int cnt=pq.top();
                pq.pop();
                cnt--;
                if(cnt>0)
                temp.push_back(cnt);
                time++;
                i++;
            }
            for(auto& it:temp) pq.push(it);
            if(pq.empty()) break;
            time+=cycle-i;
        }
        return time;
    }
};