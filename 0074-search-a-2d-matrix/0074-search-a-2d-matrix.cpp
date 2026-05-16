class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();

          //find correct row 
          //so i make take only 0th col element 
          //find row where value is just minimum 
           
          int u=0,d=m-1;
          while(u<d){
            int mid=(u+d+1)/2;
            if(matrix[mid][0]==target) return true;
            else if(matrix[mid][0]<target) u=mid;
            else d=mid-1;
          }  

        // we got row 
        //now find 1d bs on this row 

        int l=0,r=n-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(matrix[u][mid]==target) return true;
            else if(matrix[u][mid]<target) l=mid+1;
            else r=mid-1;
        }
    return false;

    }
};