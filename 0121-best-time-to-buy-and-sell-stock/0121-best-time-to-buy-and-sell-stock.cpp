class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int ans=0;
        int buy=INT_MAX;
        int sell=INT_MIN;
        for(int i=0;i<n;i++){
             buy=min(buy,prices[i]);
            sell=max(sell,prices[i]);
            ans=max(ans,(sell-buy));
            sell=0;
        }
        return ans;
    }
};