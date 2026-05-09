class Solution {
public:
    void find(int idx,int sz,int target,vector<int>& ds,vector<vector<int>>& ans){

        if(target==0 and ds.size()==sz){
            ans.push_back(ds);
            return;
        }
        //pruning
        if(target<0 || ds.size()>sz) return ;

        for(int i=idx;i<=9;i++){
            ds.push_back(i);
            find(i+1,sz,target-i,ds,ans);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> ds;
        find(1,k,n,ds,ans);
        return ans;
    }
};