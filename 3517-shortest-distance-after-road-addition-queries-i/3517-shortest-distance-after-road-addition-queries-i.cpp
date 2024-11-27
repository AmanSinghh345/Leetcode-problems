class Solution {
public:
    int shortestDistance(int n,vector<vector<int>>& adj){
        vector<int> visited(n,0);
        visited[0]=1;
        int x=0;
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int size=q.size();
           for(int i=0;i<size;i++){
            int node=q.front();
            q.pop();
            if(node==n-1) return x;
            for(auto it:adj[node]){
                if(!visited[it]){
                    visited[it]=1;
                    q.push(it);
                }
            }
           }
           x++;
        }
        return x;
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> adj(n);
        for(int i=0;i<n-1;i++){
            adj[i].push_back(i+1);}
            vector<int> ans;
            for(auto& query:queries){
                adj[query[0]].push_back(query[1]);
                ans.push_back(shortestDistance(n,adj));
            }
            return ans;
        
    }
};