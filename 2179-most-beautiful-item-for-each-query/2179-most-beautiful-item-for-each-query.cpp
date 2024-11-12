class Solution {
    #define pii pair<int,int>
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        vector<pii> query;
        int m=queries.size();
        for(int i=0;i<m;++i)
            query.push_back({queries[i],i});
        
        sort(query.begin(),query.end());
        sort(items.begin(),items.end());
        vector<int> res(m);

        int n=items.size();
        int item_pos=0;
        int max_beauty=0;
        for(int i=0;i<m;++i){
            while(item_pos<n and items[item_pos][0]<=query[i].first){
                max_beauty = max(max_beauty,items[item_pos][1]);
                item_pos++;
            }
            res[query[i].second] = max_beauty;
        }
        return res;
    }
};