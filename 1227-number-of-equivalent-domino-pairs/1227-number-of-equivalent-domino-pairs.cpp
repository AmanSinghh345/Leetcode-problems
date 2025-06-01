class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int m = dominoes.size();
        int n = dominoes[0].size();
        int ans = 0;

        //   Solution 1 TLE
        // for(int i=0;i<m-1;i++){

        //     for(int j=i+1;j<m;j++){
        //         if((dominoes[i][0]==dominoes[j][0] and
        //         dominoes[i][1]==dominoes[j][1]) or
        //         (dominoes[i][0]==dominoes[j][1] and
        //         dominoes[i][1]==dominoes[j][0])){
        //             ans++;
        //     }
        //     }
        // }
        // Solution 2 Maths
        vector<int> cnt(100, 0);
        for (auto& it : dominoes) {
            int val =
                (it[0] < it[1]) ? (it[1] * 10) + it[0] : (it[0] * 10) + it[1];
                ans+=cnt[val];
            cnt[val]++;
        }
        /*
         
          ans  0 +  1 +  2 + 3
           cnt   1  2  3    4
        */

        return ans;
    }
};