class Solution {
public:
int pairsExists(vector<int>& nums,int mid){
    int i=0,res=0;
    int n=nums.size();
    while(i<n-1){
        if(nums[i+1]-nums[i]<=mid){
            res++;
            i++;
        }
        i++;
    }
    return res;
}
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        long long l=0,h=nums.back()-nums.front();
        while(l<h){
            int mid=l+(h-l)/2;
            if(pairsExists(nums,mid)>=p){
                h=mid;
            }
            else l=mid+1;
        }
        return l;
    }
};