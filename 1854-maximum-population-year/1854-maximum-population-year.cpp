class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        map<int,int> mp;
        for(auto log:logs){
            mp[log[0]]++;
            mp[log[1]]--;
        }
        int pref=0;
        int maxi=0;
        int ans=-1;
        for(auto it : mp){
            pref+=it.second;
            if(pref>maxi){
                pref=maxi;
                ans=it.first;
            }
        }
        return ans;
    }
};