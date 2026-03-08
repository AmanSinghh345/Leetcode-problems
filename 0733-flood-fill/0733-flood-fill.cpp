class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size();
        int n=image[0].size();
        vector<vector<int>> ans=image;
       
        queue<pair<int,int>> q;
        vector<vector<int>> vis(m,vector<int> (n,0));

        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};

        q.push({sr,sc});
        vis[sr][sc]=1;
        ans[sr][sc]=color;
        while(!q.empty())
        {
            auto curr=q.front();
            q.pop();

            int row=curr.first;
            int col=curr.second;

            for(int i=0;i<4;i++)
            {
                int nrow=row+dx[i];
                int ncol=col+dy[i];
                
                if(nrow>=0 and nrow<m and ncol>=0 and ncol<n and vis[nrow][ncol]==0 and image[nrow][ncol]==image[row][col])
                {
                    vis[nrow][ncol]=1;
                    ans[nrow][ncol]=color;
                    q.push({nrow,ncol});
                }
            }

        }
        return ans;
    }
};