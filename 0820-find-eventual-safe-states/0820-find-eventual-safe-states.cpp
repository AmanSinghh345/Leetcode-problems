class Solution {
public:
    bool DFSRec(int s,vector<bool>& visited,vector<bool>& dfsVisited,vector<vector<int>> & graph,vector<bool>& presentCycle){
        visited[s]=true;
        dfsVisited[s]=true;
        vector<int> data=graph[s];
        for(auto x:data){
            if(!visited[x]){
                if(DFSRec(x,visited,dfsVisited,graph,presentCycle)){
                    return presentCycle[s]=true;
                }
                
            }
            else if(visited[x] && dfsVisited[x]) {
                return presentCycle[s]=true;
            }
        }
        dfsVisited[s]=false;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> ans;
        int n=graph.size();
        vector<bool> visited(n,false),dfsVisited(n,false);
        vector<bool> presentCycle(n,false);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                DFSRec(i,visited,dfsVisited,graph,presentCycle);
            }
        }
        for(int i=0;i<n;i++){
            if(!presentCycle[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};