class Solution {
public:
    class Fenwick{
        public:
        int n;
        vector<int> bits; 
        Fenwick(int n){
            this->n=n;
            bits.assign(n+1,0);
        }
        void update(int idx,int val){
            while(idx<=n){
                bits[idx]+=val;
                idx+=(idx&-idx);
            }
        }
        long long query(int idx){
            long long res=0;
            while(idx>0){
               res+= bits[idx];
               idx-=(idx&-idx);
            }
            return res;
        }
    };
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n=nums.size();
      
        vector<long long > prefix(n+1,0);
        long long  pref=0;
        for(int i=0;i<n;i++){
            if(nums[i]==target) pref++;
            else pref--;
            prefix[i+1]=pref;
        }

        Fenwick fw(n);
        vector<long long> vals=prefix;
        sort(vals.begin(),vals.end());
        vals.erase(unique(vals.begin(),vals.end()),vals.end());

        auto getIndex=[&](long long x ){
            return lower_bound(vals.begin(),vals.end(),x)-vals.begin()+1;
        };
        long long cnt=0;
        for(int i=0;i<=n;i++){
            int idx=getIndex(prefix[i]);
            cnt+=fw.query(idx-1);
            fw.update(idx,1);
        }
        return cnt;
    }
};