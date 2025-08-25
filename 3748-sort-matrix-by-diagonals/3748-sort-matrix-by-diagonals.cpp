class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        for(int i=0;i<row;i++)
        {
            int j=0,I=i;
            vector<int> temp;
            while(i>=0 and i<row and j>=0 and j<col)
            {
                temp.push_back(grid[i][j]);
                i++;
                j++;
            }
            sort(temp.rbegin(),temp.rend());
            i=I,j=0;
            int cnt=0;
            while(i>=0 and i<row and j>=0 and j<col)
            {
                grid[i][j]=temp[cnt];
                cnt++;
                i++;
                j++;
            }
            i=I;
        }
        for(int j=1;j<col;j++)
        {
            int J=j,i=0;
            vector<int> temp;
            while(i>=0 and i<row and j>=0 and j<col)
            {
                temp.push_back(grid[i][j]);
                i++;
                j++;
            }
            sort(temp.begin(),temp.end());
            j=J;
            i=0;
            int cnt=0;
            while(i>=0 and i<row and j>=0 and j<col)
            {
                grid[i][j]=temp[cnt];
                i++;
                j++;
                cnt++;
            }
            j=J;
        }
        return grid;
    }
};