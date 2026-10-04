class Solution {
public:
    int check(vector<int>& piles,int k){
        int cnt=0;
        for(int x:piles){
            cnt+=(x+k-1)/k;
        }
        return cnt;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int l=1,r=*max_element(piles.begin(),piles.end());
        while(l<r){
            int mid=(l+r)/2;
            if(check(piles,mid)<=h){
                r=mid;
            }
            else l=mid+1;
        }
        return r;
    }
};