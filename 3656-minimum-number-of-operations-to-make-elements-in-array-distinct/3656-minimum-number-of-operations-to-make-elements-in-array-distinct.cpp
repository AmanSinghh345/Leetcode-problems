class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<int,int> umap;
        int cnt=0;
        int n=nums.size();
        for(int i=nums.size()-1;i>=0;i--){
            umap[nums[i]]++;
            if(umap[nums[i]]>1){
                int x=n-cnt;
                return (x+3-1)/3;
            }
            cnt++;

        
        }
        return 0;
    }
};