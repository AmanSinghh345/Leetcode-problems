class Solution {
public:
    void find(int i,int sum,int k,int n,vector<int>& a ,vector<int>& ds,vector<vector<int>>& ans){

        if(i==a.size()){
            if(sum==n and ds.size()==k){
                ans.push_back(ds); 
            }
            return;
        }
        ds.push_back(a[i]);
        find(i+1,sum+a[i],k,n,a,ds,ans);
        ds.pop_back();
        find(i+1,sum,k,n,a,ds,ans);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> a={1,2,3,4,5,6,7,8,9};
        vector<int> ds;
        find(0,0,k,n,a,ds,ans);
        return ans;
    }
};