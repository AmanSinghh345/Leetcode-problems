class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int totalApple=accumulate(apple.begin(),apple.end(),0);
        sort(capacity.rbegin(),capacity.rend());
        int cnt=0;
        int ans=0;
        
        for(int i=0;i<capacity.size();i++)
        {
            if(cnt>=totalApple) return ans;
            cnt+=capacity[i];
            ans++;
           
        }
        return ans;
    }
};