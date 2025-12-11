class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        vector<int> maxRow(n+1,0);
        vector<int> maxCol(n+1,0);
        vector<int> minRow(n+1,n+1);
        vector<int> minCol(n+1,n+1);

        for(int i=0;i<buildings.size();i++)
        {
            int x=buildings[i][0];
            int y=buildings[i][1];

            maxRow[y]=max(maxRow[y],x);
            maxCol[x]=max(maxCol[x],y);
            minRow[y]=min(minRow[y],x);
            minCol[x]=min(minCol[x],y);
        }
        int cnt=0;
        for(int i=0;i<buildings.size();i++)
        {
             int x=buildings[i][0];
            int y=buildings[i][1];
            if(x>minRow[y] and x<maxRow[y]
            and y>minCol[x] and y<maxCol[x])
            cnt++;
        }
        return cnt;
    }

};