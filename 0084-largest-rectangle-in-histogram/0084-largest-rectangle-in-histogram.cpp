class Solution {
public:
    /*
    formula area=arr[i](nse-pse-1)
    find nse and pse for each index then apply this formula and take the maximum
    */
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> nse(n,-1);
        stack<int> st;
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() and heights[st.top()]>=heights[i])
            {
                st.pop();
            }
            if(st.empty()){
                nse[i]=n;
            }
            else nse[i]=st.top();
            st.push(i);
        }

        vector<int> pse(n,-1);
        stack<int> stt;
        for(int i=0;i<n;i++)
        {
            while(!stt.empty() and heights[stt.top()]>=heights[i])
            {
                stt.pop();
            }
            if(stt.empty())
            {
                pse[i]=-1;
            }
            else pse[i]=stt.top();
            stt.push(i);
        }
        int maxi=INT_MIN;
        for(int i=0;i<n;i++)
        {
            maxi=max(maxi,(heights[i]*(nse[i]-pse[i]-1)));
        }
        return maxi;
    }
};