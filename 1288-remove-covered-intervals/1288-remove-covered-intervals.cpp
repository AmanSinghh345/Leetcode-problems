class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
    
        sort(intervals.begin(),intervals.end(),[](auto a ,auto b){
            if(a[0]!=b[0]) return a[0]<b[0];
            else return a[1]>b[1];
        });
        int cnt=0;
        int prev=0;
        for(auto& it : intervals){
            if(it[1]>prev){
                cnt++;
                prev=it[1];
            }
        }
        return cnt;
    }
};