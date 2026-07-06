class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        int cnt=n;
        sort(intervals.begin(),intervals.end(),[](auto a ,auto b){
            if(a[0]!=b[0]) return a[0]<b[0];
            else return a[1]>b[1];
        });
        int l=0,r=1;
        while(r<n){
            while(r<n && intervals[l][0]<=intervals[r][0] && intervals[r][1]<=intervals[l][1]){
                    r++;
                    cnt--;
            }
            l=r;
            r++;

        }
        return cnt;
    }
};