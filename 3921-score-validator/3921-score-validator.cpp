class Solution {
public:
    vector<int> scoreValidator(vector<string>& events) {
        int n=events.size();
        vector<int> ans(2,0);
        for(int i=0;i<n;i++){
            if(events[i]=="W") ans[1]++;
            else if(events[i]=="WD" || events[i]=="NB") ans[0]++;
            else{
                int num=stoi(events[i]);
                ans[0]+=num;
            }
            if(ans[1]==10) break;
        }
        return ans;
    }
};