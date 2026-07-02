class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> best(m,vector<int> (n,-1));
        if(grid[0][0]) best[0][0]=health-1;
        else best[0][0]=health;
        priority_queue<tuple<int,int,int>> pq;
        pq.push({best[0][0],0,0});
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};

        while(!pq.empty()){
            auto [curr,x,y]=pq.top();
            cout<<curr<<" "<<x<<" "<<y<<"\n";
            pq.pop();

            if(curr<best[x][y]) continue;
            if(curr==0) continue;

            for(int k=0;k<4;k++){
                int nx=x+dx[k];
                int ny=y+dy[k];
                int temp=curr;
                if(nx>=0 && nx<m && ny>=0 && ny<n){
                    if(grid[nx][ny])  temp--;
                    if(temp==0) continue;
                    if(best[nx][ny]<temp){
                        best[nx][ny]=temp;
                        pq.push({temp,nx,ny});
                    }
                }
            }
        }

        if(best[m-1][n-1]>0)  return true;
        return false;

    }
};