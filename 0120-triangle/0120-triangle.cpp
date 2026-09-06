class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        int n=m;
        vector<int> prev(m);
        for(int j=0;j<m;j++){
            prev[j]=triangle[m-1][j];
        }

        for(int i=m-2;i>=0;i--){
            vector<int> curr(m);
          
            for(int j=0;j<triangle[i].size();j++){
                curr[j]=triangle[i][j]+min(prev[j],prev[j+1]);
            }
             prev=curr;
        }
        return prev[0];
    }
};