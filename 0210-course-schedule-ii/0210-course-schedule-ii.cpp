class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses,0);

        for(int i=0;i<prerequisites.size();i++){
            int course=prerequisites[i][0];
            int prereq=prerequisites[i][1];
            adj[prereq].push_back(course);
            indegree[course]++;
        }

        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0) q.push(i);
        }
        vector<int> ans;
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            ans.push_back(node);

            for(int neigh:adj[node]){
                indegree[neigh]--;
                if(indegree[neigh]==0){
                    q.push(neigh);
                }
            }
        }
        if(ans.size()!=numCourses) return {};
        return ans;
    }
};