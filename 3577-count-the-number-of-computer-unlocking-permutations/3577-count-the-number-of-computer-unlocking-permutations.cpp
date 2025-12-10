class Solution {
public:
    int mod=1e9 + 7;
    int countPermutations(vector<int>& complexity) {
        int curMin=complexity[0];
        int ans=1;
        int n=complexity.size();
        vector<int> a;
        for(int i=1;i<n;i++)
        {   
            if(complexity[i]<=curMin) return 0;
            a.push_back(complexity[i]);
        }
        for(int i=2;i<=n-1;i++)
        {
            ans=(1LL*ans*i)%mod;
        }
        return ans;
    }
};