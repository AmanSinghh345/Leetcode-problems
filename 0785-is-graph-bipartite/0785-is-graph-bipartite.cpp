class Solution {
public:
    bool dfs(int i,vector<int>& color,vector<vector<int>>& graph){
        
        for(int neigh : graph[i]){
            if(color[neigh]==-1){
                color[neigh]=color[i]==0?1 : 0;
                if(!dfs(neigh,color,graph)) return false;
            }
            else if(color[neigh]==color[i]) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n,-1);

        for(int i=0;i<n;i++){
            if(color[i]==-1){
                color[i]=0;
                if(!dfs(i,color,graph)) return false;
            }
        }
        return true;
    }
};