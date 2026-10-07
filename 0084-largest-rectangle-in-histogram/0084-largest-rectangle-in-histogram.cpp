class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> pse(n,-1);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]) st.pop();
            if(!st.empty()) pse[i]=st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        vector<int> nse(n,n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i]) st.pop();
            if(!st.empty()) nse[i]=st.top();
            st.push(i);
        }
        int ans=0;
        for(int x:pse) cout<<x<<" ";
        cout<<endl;
        for(int x:nse) cout<<x<<" ";
        cout<<endl;
        for(int i=0;i<n;i++){
            int area=heights[i]*(nse[i]-pse[i]-1);
            ans=max(ans,area);
        }
        return ans;
    }
};