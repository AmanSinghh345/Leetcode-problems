class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int, vector<int>> umap;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            umap[arr[i]].push_back(i);
        }
       
        // bfs to find the minimum ops
        queue<int> q;
        vector<int> vis(n, 0);
        int cnt=0;
    
        q.push(0);
        vis[0] = 1;

        while(!q.empty())
        {
            int  sz=q.size();
            while(sz--)
            {
                int node=q.front();
                q.pop();

                if(node==n-1) return cnt;
                if(node-1>=0 and !vis[node-1]) {
                    vis[node-1]=1;
                    q.push(node-1);
                }
                 if(node+1<=n-1 and !vis[node+1])
                {
                    vis[node+1]=1;
                    q.push(node+1);
                }

                for(int x:umap[arr[node]])
                {
                    if(vis[x]==0)
                    {
                        vis[x]=1;
                        q.push(x);
                    }
                }
                umap.erase(arr[node]);
            }
            cnt++;
        }
        return -1;
    }
};