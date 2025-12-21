class Solution {
public:
    using ll =long long ;
    ll ans=0;
    vector<int> gcnts;
    vector<vector<int>> adj;
    vector<int> vg;
    vector<int> dfs(int x,int p)
    {
        vector<int> res(21,0);
        res[vg[x]]++;
        for(auto it: adj[x])
        {
            if(it==p) continue;
            
            vector<int> ycnts=dfs(it,x);
            for(int i=1;i<=20;i++)
            {
                if(ycnts[i]<=0 ) continue;
                res[i]+=ycnts[i];
                ll cnt_in=ycnts[i];
                ll  cnt_out=gcnts[i]-cnt_in;
                ans+=cnt_in*cnt_out;
            }
        }
        return res;
    }
    long long interactionCosts(int n, vector<vector<int>>& edges, vector<int>& group) {
        ans=0;
        adj.assign(n,vector<int> ());
        vg=group;
        gcnts.assign(21,0);

        for(auto & edge: edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        for(auto g:group) gcnts[g]++;
        dfs(0,-1);
        return ans;

    }
};