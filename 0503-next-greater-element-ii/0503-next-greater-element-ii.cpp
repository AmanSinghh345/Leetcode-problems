class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int> nge(n,-1);
        vector<int> a;
        int t=2 ;
        while(t--)
        {
            for(int i=0;i<n;i++)
            {
                a.push_back(nums[i]);
            }
        }
        stack<int> st;
        for(int i=2*n-1;i>=0;i--)
        {
            while(!st.empty() and st.top()<=a[i])
            {
                st.pop();
            }
            if(i<n)
            {
                if(st.empty()) nge[i]=-1;
                else nge[i]=st.top();
            }
            st.push(a[i]);
        }
        return nge;
    }
};