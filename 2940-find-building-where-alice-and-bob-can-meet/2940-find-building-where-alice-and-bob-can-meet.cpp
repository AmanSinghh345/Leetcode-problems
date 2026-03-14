class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();
        int q = queries.size();

        vector<int> ans(q, -1);
        vector<vector<pair<int,int>>> wait(n);

        for(int i = 0; i < q; i++){
            int a = queries[i][0];
            int b = queries[i][1];

            if(a > b) swap(a,b);

            if(a == b){
                ans[i] = b;
            }
            else if(heights[a] < heights[b]){
                ans[i] = b;
            }
            else{
                wait[b].push_back({max(heights[a],heights[b]), i});
            }
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        for(int i = 0; i < n; i++){

            for(auto &x : wait[i]){
                pq.push(x);
            }

            while(!pq.empty() && pq.top().first < heights[i]){
                ans[pq.top().second] = i;
                pq.pop();
            }
        }

        return ans;
    }
};