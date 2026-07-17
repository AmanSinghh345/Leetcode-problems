#define ll long long 
class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int maxi=*max_element(nums.begin(),nums.end());

        vector<long long > freq(maxi+1,0);
        for(int x:nums) freq[x]++;

        vector<long long> exact(maxi+1,0);
        for(int g=maxi;g>=1;g--){
            ll cnt=0;
            for(ll mul=g;mul<=maxi;mul+=g){
                cnt+=freq[mul];
            }
            exact[g]=(cnt*(cnt-1))/2;
            for(ll mul=2*g;mul<=maxi;mul+=g){
                exact[g]-=exact[mul];
            }

            
           

        }
        for(int i=1;i<=maxi;i++) exact[i]+=exact[i-1];

         vector<int> ans;
            for(ll q:queries){
                int val=lower_bound(exact.begin()+1,exact.end(),q+1)-exact.begin();
                ans.push_back(val);
            }
        return ans;
    }
};