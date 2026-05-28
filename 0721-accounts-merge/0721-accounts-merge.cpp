class Disjoint{
    vector<int> parent;
    vector<int> size;
    public : 
    Disjoint(int n){
        parent.resize(n);
        size.resize(n,1);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }

    int find(int node){
        if(parent[node]==node) return node;
        return parent[node]=find(parent[node]);
    }
    void unionBySize(int a,int b){
        int pa=find(a);
        int pb=find(b);

        if(pa==pb) return;

        if(size[pa]<size[pb]){
            parent[pa]=pb;
            size[pb]+=size[pa];
        }
        else{
            parent[pb]=pa;
            size[pa]+=size[pb];
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        Disjoint ds(n);

        vector<vector<string>> ans;
        unordered_map<string,int> umap;

        for(int i=0;i<n;i++){
            for(int j=0;j<accounts[i].size();j++){
                if(j==0) continue;
                if(umap.count(accounts[i][j])){
                    ds.unionBySize(i,umap[accounts[i][j]]);
                }
                else umap[accounts[i][j]]=i;
            }
        }

        vector<vector<string>> merged(n);
        for(auto& it : umap){
            string mail=it.first;
            int ind=it.second;

            int ultp=ds.find(ind);
             merged[ultp].push_back(mail);
           
        }
        for(int i=0;i<n;i++){
            if(merged[i].empty()) continue;

            vector<string> temp;
            temp.push_back(accounts[i][0]);

            sort(merged[i].begin(),merged[i].end());

            for(auto& it : merged[i]) temp.push_back(it);
            ans.push_back(temp);
        }
        return ans;
    }
};