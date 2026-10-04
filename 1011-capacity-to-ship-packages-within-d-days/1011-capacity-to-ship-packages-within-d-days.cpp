class Solution {
public:
    int check(vector<int>& weights,int k){
        int curr=0;
        int cnt=1;
        for(int x:weights){
            if(x+curr<=k){
                curr+=x;
            }
            else{
                curr=x;
                cnt++;
            }
        }
        return cnt;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int l=*max_element(weights.begin(),weights.end());
        int n=weights.size();
        int h=n*500;
        while(l<h){
            int mid=(l+h)/2;
            if(check(weights,mid)<=days) h=mid;
            else l=mid+1;
        }
        return l;
    }
};