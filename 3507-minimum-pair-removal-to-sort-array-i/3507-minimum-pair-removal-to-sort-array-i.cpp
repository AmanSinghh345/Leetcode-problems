class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n=nums.size();
       
        if(is_sorted(nums.begin(),nums.end())) return 0;
        vector<int> a(nums.begin(),nums.end());
        int cnt=0;
        while(true)
        {
        
        if(is_sorted(a.begin(),a.end())) return cnt;
        else {
            
            int ind; int mini=INT_MAX;
            for(int i=0;i<a.size()-1;i++)
            {
                if(a[i]+a[i+1]<mini)
                {
                    mini=a[i]+a[i+1];
                    ind=i;
                }
            }
            cnt++;
            vector<int> temp;
            for(int i=0;i<ind;i++) temp.push_back(a[i]);
            temp.push_back(a[ind]+a[ind+1]);
            for(int i=ind+2;i<a.size();i++) temp.push_back(a[i]);
            a=temp;
        }
        }
        return -1;
    }
};