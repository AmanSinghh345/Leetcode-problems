class Solution {
public:
    void dfs(int x,vector<int>& ans,int low ,int high){
        if(x>high) return ;
        if(x>=low && x<=high) ans.push_back(x);
        int ld=x%10;
        if(ld==9 ) return;
        int num=x*10 + ld +1;
        if(num<=high) dfs(num,ans,low,high); 
    }
    vector<int> sequentialDigits(int low, int high) {
        
        vector<int> ans;
       
        for(int i=1;i<=9;i++){
             dfs(i,ans,low ,high);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};