class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int,int>> arr;
        for(int i=0;i<n;i++){
            arr.push_back({nums[i],i});
        }
        sort(arr.begin(),arr.end());


        vector<int> val(n),pos(n);
        for(int i=0;i<n;i++){
            val[i]=arr[i].first;
            pos[arr[i].second]=i;
        }
        
        int LOG=1;
        while((1<<LOG)<=n) LOG++;

        //fartest with one jump;
        vector<int> nxt(n);
        int r=0;
        for(int i=0;i<n;i++){
            if(r<i) r=i;
            while(r+1<n && val[r+1]-val[i]<=maxDiff){
                r++;
            }
            nxt[i]=r;
        }

        vector<vector<int>> up(n,vector<int>(LOG));
        for(int i=0;i<n;i++){
            up[i][0]=nxt[i];
        }

        for(int j=1;j<LOG;j++){
            for(int i=0;i<n;i++){
                up[i][j]=up[up[i][j-1]][j-1];
            }
        }

        vector<int> ans;
        for(auto & q : queries){
            int u=pos[q[0]];
            int v=pos[q[1]];

            if(u==v) {
                ans.push_back(0);
                continue;
            }
            if(u>v) swap(u,v);

            int curr=u;
            int step=0;

            for(int j=LOG-1;j>=0;j--){
                
                    if(up[curr][j]<v) {
                        curr=up[curr][j];
                        step+=(1<<j);
                    }
                
            }
            if(up[curr][0]>=v) {
                step++;
                ans.push_back(step);
            }
            else ans.push_back(-1);

        }
        return ans;
    }
};