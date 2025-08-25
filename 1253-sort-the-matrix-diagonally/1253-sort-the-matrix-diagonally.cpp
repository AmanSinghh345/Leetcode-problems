class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int row=mat.size();
        int col=mat[0].size();
        for(int j=0;j<col;j++)
        {
            int i=0,J=j;
            vector<int> temp;
            while(i>=0 and i < row and j>=0 and j<col)
            {   
                temp.push_back(mat[i][j]);
                i++;
                j++;
            }
            sort(temp.begin(),temp.end());
            j=J;
            i=0;
            int ind=0;
            while(i>=0 and i<row and j>=0 and j<col)
            {
                mat[i][j]=temp[ind];
                i++;
                j++;
                ind++;
            }
            j=J;
        }
        for(int i=1;i<row;i++)
        {
            int I=i;
            int j=0;
            vector<int> temp;
            while(i>=0 and i<row and j>=0 and j<col)
            {
                temp.push_back(mat[i][j]);
                i++;
                j++;
            }
            sort(temp.begin(),temp.end());
            j=0, i= I;
            int cnt=0;
            while(i>=0 and i<row and j>=0 and j<col)
            {
                mat[i][j]=temp[cnt];
                cnt++;
                i++;
                j++;
            }
            i=I;
            }
        return mat;
    }
};