class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<int> arr;
        for(int j=0;j<triangle[n-1].size();j++)
        {
            arr.push_back(triangle[n-1][j]);
        }
        for(int i=n-2;i>=0;i--)
        {
            for(int j=0;j<triangle[i].size();j++)
            {
                 arr[j]=triangle[i][j]+min(arr[j],arr[j+1]);
            }
        }
        return arr[0];
    }
};