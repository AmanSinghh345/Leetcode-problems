class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n=nums.size();
        int f=0;
       
        for(int i=0;i<n-2;i++){
             vector<float> v={};
            for(int j=i;j<i+3;j++){
                float t=nums[j];
              v.push_back(t);
            } 
            float sum=v[0]+v[2];
            float mi= v[1]/2.0;
            if(mi==sum) f++;
        }
        return f;
    }
};