class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int ans=0;
        map<int,int> mpp;
        for(int i=0;i<nums1.size();i++){
           mpp[nums1[i]]++;
        }
        for(auto it=mpp.begin();it!=mpp.end();++it){
            if(it->second%2!=0){
                for(int i=0;i<nums2.size();i++){
                    ans^=(it->first^nums2[i]);
                }
            }
        }
        return ans;
    }
};