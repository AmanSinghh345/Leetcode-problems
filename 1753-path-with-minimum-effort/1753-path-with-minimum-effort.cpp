class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();

        vector<vector<int>> dist(m,vector<int> (n,1e9));
        dist[0][0]=0;

        using T=pair<int,pair<int,int>>;
        priority_queue<T,vector<T>,greater<T>> pq;

        pq.push({0,{0,0}});
        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};

        while(!pq.empty())
        {
            auto [d,cell]=pq.top();
            pq.pop();
            int x=cell.first;
            int y=cell.second;
            int old=d;

            if(x==m-1 and y==n-1) return d;

            if(d>dist[x][y]) continue;

            for(int i=0;i<4;i++)
            {
                int newr=x+dx[i];
                int newc=y+dy[i];
                if(newr>=0 and newr<m and newc>=0 and newc<n)
                {
                    int neew=max(old,abs(heights[newr][newc]-heights[x][y]));
                    if(neew<dist[newr][newc])
                    {
                        dist[newr][newc]=neew;
                    pq.push({dist[newr][newc],{newr,newc}});
                    }
                }
            }

        }
        return dist[m-1][n-1];
    }
};