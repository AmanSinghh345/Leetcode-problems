class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int> prefix(101,0);
        for(int i=0;i<(int)logs.size();i++){
                int birth=logs[i][0]-1950;
                int death=logs[i][1]-1950;

                prefix[birth]++;
                prefix[death]--;
        }
        int maxi=prefix[0];
        int idx=0;
        for(int i=1;i<101;i++){
            prefix[i]+=prefix[i-1];
            if(prefix[i]>maxi) {
                maxi=prefix[i];
                idx=i;
            }
        }
        return idx+1950;
    }
};