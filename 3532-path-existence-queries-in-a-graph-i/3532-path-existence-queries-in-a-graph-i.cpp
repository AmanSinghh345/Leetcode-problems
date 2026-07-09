class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> component(n,0);
        int comp=0;
        for(int i=1;i<n;i++){
            if(nums[i]-nums[i-1]>maxDiff) comp++;
            component[i]=comp;
        }

        vector<bool> ans;
        for(auto it : queries){
            int u=it[0];
            int v=it[1];

            if(component[u]==component[v]) ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};