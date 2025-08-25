class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int row=mat.size();
        int col=mat[0].size();
        vector<vector<int>> ans(row+col-1);
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                ans[i+j].push_back(mat[i][j]);
            }
        }
        vector<int> res;
        for(int i=0;i<ans.size();i++)
        {
            if(i%2==0)
            {
                reverse(ans[i].begin(),ans[i].end());
            }
            for(int j=0;j<ans[i].size();j++)
            {
                res.push_back(ans[i][j]);
            }
        }
        return res;
    }
};