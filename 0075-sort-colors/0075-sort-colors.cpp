class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> cntArr(3,0);
        for(int x: nums) cntArr[x]++;
        int j=0;
        int i=0;
        while(j<3){
            while(cntArr[j]>0){
                nums[i]=j;
                i++;
                cntArr[j]--;
            }
            j++;
        }
    }
};