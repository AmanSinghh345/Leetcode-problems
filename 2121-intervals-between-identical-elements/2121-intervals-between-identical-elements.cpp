class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        int n=arr.size();
        unordered_map<long ,vector<long long> > mp;
        for(int i=0;i<n;i++) mp[arr[i]].push_back(i);

        vector<long long > ans(n);
        for(auto & it : mp){
            long long  key=it.first;
            vector<long long > v=it.second;
            long long len=v.size();
            vector<long long> pref(len+1,0);
            for(int i=1;i<=len;i++) pref[i]=pref[i-1]+v[i-1];

            for(int i=1;i<=len;i++){
                int n1=i-1;
                int n2=len-i;
                long long rightAdd=pref[len]-pref[i];
                long long rightSub=n2*v[i-1];
                long long leftAdd=n1*(v[i-1]);
                long long leftSub=pref[i-1];

                long long val=(leftAdd-leftSub)+(rightAdd-rightSub);
                ans[v[i-1]]=val;
            }

        }
        return ans;
    }
};