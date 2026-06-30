class Solution {
public:
    long long appealSum(string s) {
        long long  n=s.size();
        unordered_map<char,long long > umap;
        long long cnt=0;
        vector<long long > ans(n,0);
        for(long long  i=0;i<n;i++){
            long long left=i+1;
            if(umap.count(s[i])) left-=(umap[s[i]]+1);
           
            long long right=n-i;
              ans[i]=(left*right);
            cnt+=(left*right); 
             umap[s[i]]=i;
          
        }
        for(int i=0;i<n;i++) cout<<ans[i]<<" ";
        return cnt;
    }
};