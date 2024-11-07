class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int n=candidates.size();                             
       int ans=0;
       for(int i=0;i<31;i++){
        int cnt=0;
        for(int j=0;j<n;j++){
            if(candidates[j]&(1<<i)){
                cnt++;
            }

        }
        ans=max(cnt,ans);

       }
       return ans;
    }
};
//  16 1000           
//  17 1001              1000
//  71 1000111
//  62  111110
//  12    1100
//  24   11000
//  14    1110