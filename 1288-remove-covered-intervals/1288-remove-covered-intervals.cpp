class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        int cnt=n;
        for(int i=0;i<n;i++){
              if(intervals[i][0]==-1 && intervals[i][1]==-1) continue;
            for(int j=0;j<n;j++){
                    if(i==j) continue;
                if(intervals[j][0]==-1 && intervals[j][1]==-1) continue;
                if(intervals[i][0]<=intervals[j][0] && intervals[j][1]<=intervals[i][1]) {
                    intervals[j][0]=-1;
                    intervals[j][1]=-1;
                    cnt--;
                }
            }
        }
        return cnt;
    }
};