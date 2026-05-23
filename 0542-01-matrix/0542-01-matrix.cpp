class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        queue<pair<int,int>> q; 
        vector<vector<int>> ans(m,vector<int>(n,-1));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0) {
                    ans[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        while(!q.empty()){
            auto[x,y]=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx>=0 && nx<m && ny>=0 && ny<n && ans[nx][ny]==-1){
                ans[nx][ny]=ans[x][y]+1;
                 q.push({nx,ny});}
            }
        }
        return ans;
    }
};