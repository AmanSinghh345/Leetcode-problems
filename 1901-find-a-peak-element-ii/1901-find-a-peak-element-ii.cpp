class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();

        int l=0,r=n-1;
        while(l<=r){
            int mid=l+(r-l)/2;

            int row=0;
            
            for(int i=0;i<m;i++){
                if(mat[i][mid]>mat[row][mid]){
                    row=i;
                }
            }            

            int left=(mid-1>=0)?mat[row][mid-1]:-1;
            int right=(mid+1<n)?mat[row][mid+1]:-1;

            if(left<mat[row][mid] && mat[row][mid]>right) return {row,mid};
            else if(left>mat[row][mid]) r=mid-1;
            else l=mid+1;
            
        }
        return {};
    }
};