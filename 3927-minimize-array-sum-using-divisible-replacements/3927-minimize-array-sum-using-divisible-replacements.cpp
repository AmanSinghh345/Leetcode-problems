class Solution {
public:
    vector<int> getFactors(int n){
        vector<int> factors;
        for(int i=1;i*i<=n;i++){
            if(n%i==0) {
                factors.push_back(i);
                if(n/i!=i) factors.push_back(n/i);
            }
        }
        sort(factors.begin(),factors.end());
        return factors;
    }
    long long minArraySum(vector<int>& nums) {
        int n=nums.size();

        unordered_map<int,int> umap;
        for(int i=0;i<n;i++) umap[nums[i]]++;


        long long ans=0;
        for(int i=0;i<n;i++){
            vector<int> f=getFactors(nums[i]);

            for(auto it: f){
                if(umap.find(it)!=umap.end()){
                    ans+=it;
                    break;
                }
            }
            
        }   
        return ans;
    }
};