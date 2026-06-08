class Solution {
public:
    int find(int l,int r,vector<int>& nums){
        int p2=0,p1=0;
        for(int i=l;i<=r;i++){
            int curr=max(p1,p2+nums[i]);
            p2=p1;
            p1=curr;
        }
        return p1;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        return max(find(0,n-2,nums),find(1,n-1,nums));
    }
};