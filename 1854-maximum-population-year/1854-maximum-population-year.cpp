class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int> vals;
        for(int i=0;i<(int)logs.size();i++){
                
                int birth=logs[i][0];
                int death=logs[i][1];
                vals.push_back(birth);
                vals.push_back(death);
        }

        sort(vals.begin(),vals.end());
        vals.erase(unique(vals.begin(),vals.end()),vals.end());

        auto getIndex=[&](int x){
                return lower_bound(vals.begin(),vals.end(),x)-vals.begin()+1;
        };
        unordered_map<int,int> umap;

        vector<int> pref(vals.size()+1,0);
        for(int i=0;i<logs.size();i++){
            int birth=logs[i][0];
            int death=logs[i][1];

            int B_idx=getIndex(birth);
            int D_idx=getIndex(death);
            umap[B_idx]=birth;
            umap[D_idx]=death;
            pref[B_idx]++;
            pref[D_idx]--;
        }
        int idx;
        int maxi=0;
        for(int i=1;i<pref.size();i++){
            pref[i]+=pref[i-1];
            if(pref[i]>maxi){
                maxi=pref[i];
                idx=i;
            }
        }
        return umap[idx];
    }
};