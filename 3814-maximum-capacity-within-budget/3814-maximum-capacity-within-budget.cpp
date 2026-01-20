class Solution {
public:
    int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {
        int n=costs.size();
        vector<vector<int>> a;
        for(int i=0;i<n;i++)
        {   
            if(costs[i]<budget)
            a.push_back({costs[i],capacity[i]});
        }
        sort(a.begin(),a.end());
        n=a.size();
        if(n==0) return 0;
        vector<int> prefMax(n,0);
        prefMax[0]=a[0][1];
        for(int i=1;i<n;i++)
        { prefMax[i]=max(prefMax[i-1],a[i][1]);
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
    
            ans=max(ans,a[i][1]);
            int left=budget-a[i][0];
         int  j = lower_bound(a.begin(), a.end(),
                    vector<int>{left, INT_MIN}) - a.begin() - 1;

            j=min(j,i-1);
            if(j>=0)
             ans=max(ans,a[i][1]+prefMax[j]);
        }
        return ans;
    }
};