class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int> st;
        int ans=0;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                int nse=i;
                int ind=st.top();
                st.pop();
                int pse;
                if(st.empty()) pse=-1;
                else pse=st.top();
                int width=nse-pse-1;
                ans=max(ans,width*heights[ind]);
            }
            st.push(i);
        }
        while(!st.empty()){
            int nse=n;
            int ind=st.top();
            st.pop();
            int pse;
            if(st.empty()) pse=-1;
            else pse=st.top();
            int width=nse-pse-1;
            ans=max(ans,width*heights[ind]);
        }
        return ans;
    }
};