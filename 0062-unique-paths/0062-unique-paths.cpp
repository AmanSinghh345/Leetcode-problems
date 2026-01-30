class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> prev(n,1);
        vector<int> curr(n);

        for(int i=1;i<m;i++)
        {
            curr[0]=1;
            for(int j=1;j<n;j++)
            {
                curr[j]=prev[j]+curr[j-1];
            }
            prev=curr;
        }
        return prev[n-1];
    }
};