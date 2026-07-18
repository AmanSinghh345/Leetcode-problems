class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int> vis(n,0);
        stack<int> st;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                cnt++;
                st.push(i);
                while(!st.empty()){
                    int node=st.top();
                    st.pop();
                    if(vis[node]) continue;
                    vis[node]=1;
                    for(int j=0;j<n;j++){
                        if(node!=j && isConnected[node][j] && !vis[j]){
                            st.push(j);
                        }
                    }
                }
            }
        }
        return cnt;
    }
};