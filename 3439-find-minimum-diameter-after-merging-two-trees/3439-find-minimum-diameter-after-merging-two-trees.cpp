class Solution {
public:
     int diameter(unordered_map<int,vector<int>>& adj,int n){
        //step1: Take random node and find the farthest node from that node
        vector<bool> visited(n,false);
        queue<int> q;
        q.push(0);
        visited[0]=true;
        int node;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                node=q.front();
                q.pop();
                visited[node]=true;
                for(int ele:adj[node]){
                    if(!visited[ele]) q.push(ele);
                }
            }
        }
     //Step2 : Now find the diameter by finding the farthest node
     q.push(node);
     int hops=0;
     vector<int> vis(n,false);
     vis[node]=true;
     while(!q.empty()){
        int size=q.size();
        for(int i=0;i<size;i++){
            int current=q.front();
            q.pop();
            vis[current]=true;
            for(int it:adj[current]){
                if(!vis[it]) q.push(it);
            }
        }
        hops++;
     }
     
    return hops-1;
     }
     int  findDiameter(vector<vector<int>> & edges){
        if(edges.size()==0) return 0;
        unordered_map<int,vector<int>> adj;
        unordered_set<int> nodes;
        for(auto&edge:edges){
            adj[edge[0]].push_back(edge[1]);
             adj[edge[1]].push_back(edge[0]);
             nodes.insert(edge[0]);
             nodes.insert(edge[1]);
        }
        return diameter(adj,nodes.size());
     }
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int diameter1=findDiameter(edges1);
        int diameter2=findDiameter(edges2);
        int radius1=(diameter1+1)/2;
        int radius2=(diameter2+1)/2;
        int  ans=radius1+1+radius2;
        return max(ans,max(diameter1,diameter2));
    }
};