class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        unordered_map<int,vector<long long >> mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }
        // for(auto it:mp){
        //     cout<<it.first<<" : ";
        //     auto v=it.second;
        //     for(int x:v) cout<<x<<" ";
        //     cout<<endl;
        // }

        vector<long long > ans(n);
        for(auto it : mp){
            vector<long long > v=it.second;
            int len=v.size();
            vector<long long > pref(len+1,0);
            for(int i=1;i<=len;i++) pref[i]=pref[i-1]+v[i-1];
          
            cout<<endl;
            for(int i=1;i<=len;i++){
                long long  n1=i-1;
                long long  n2=len-i;
                long long  rightAdd=pref[len]-pref[i];
                long long  rightSub=n2*v[i-1];
                long long leftAdd=n1*v[i-1];
                long long leftSub=pref[i-1];
                cout<<rightAdd<<" "<<rightSub<<" "<<leftAdd<<" "<<leftSub<<endl;
                long long val=(leftAdd-leftSub)+(rightAdd-rightSub);
                ans[v[i-1]]=val;
            } 

        }
        return ans;
    }
};