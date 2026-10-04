class Solution {
public:
    int check(vector<int>& bloomDay,int k,int mid){
        int curr=0;//flowers cont.
        int cnt=0; // bouquets
        for(int x:bloomDay){
            if(x<=mid){
                curr++;
                if(curr==k){
                    cnt++;
                    curr=0;
                }
            }
            else curr=0;
        }
        return cnt;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        if(k*n<m or n<m) return -1;
        int l=*min_element(bloomDay.begin(),bloomDay.end());
        int h=*max_element(bloomDay.begin(),bloomDay.end());
        int ans;
        while(l<=h){
            int mid=(l+h)/2;
            if(check(bloomDay,k,mid)>=m){
                ans=mid;
                h=mid-1;
            }
            else l=mid+1;
        }
        if(ans==INT_MAX) return -1;
        return ans;
    }
};