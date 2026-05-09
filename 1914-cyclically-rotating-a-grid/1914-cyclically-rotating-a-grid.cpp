class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        int layers=min(m,n)/2;
        for(int l=0;l<layers;l++){
            vector<int> v;

            int rowmin=l;
            int rowmax=m-l-1;
            int colmin=l;
            int colmax=n-l-1;

            // top 
            for(int j=colmin;j<=colmax;j++){
                v.push_back(grid[rowmin][j]);
            }
            //right
            for(int i=rowmin+1;i<=rowmax-1;i++){
                v.push_back(grid[i][colmax]);
            }
            //bottom
            for(int j=colmax;j>=colmin;j--){
                v.push_back(grid[rowmax][j]);
            }
            //left
            for(int i=rowmax-1;i>=rowmin+1;i--){
                v.push_back(grid[i][colmin]);
            }
            int sz=v.size();
            int rot=k%sz;

            rotate(v.begin(),v.begin()+rot,v.end());

            int ind=0;
            for(int j=colmin;j<=colmax;j++){
                grid[rowmin][j]=v[ind++];

            }
            for(int i=rowmin+1;i<=rowmax-1;i++){
                grid[i][colmax]=v[ind++];
            }
            for(int j=colmax;j>=colmin;j--){
                grid[rowmax][j]=v[ind++];
            }
            for(int i=rowmax-1;i>=rowmin+1;i--){
                grid[i][colmin]=v[ind++];
            }
        }
        return grid;
    }
};