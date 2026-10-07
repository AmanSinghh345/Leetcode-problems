class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int> heights(n,0);
        int ans=0;
        for(int i=0;i<m;i++){

            for(int j=0;j<n;j++){
                if(matrix[i][j]=='0') heights[j]=0;
                else heights[j]++;
            }
            for(int x:heights) cout<<x<<" ";
            cout<<endl;
            stack<int> st;
            for(int i=0;i<n;i++){
                while(!st.empty() && heights[st.top()]>=heights[i]){
                    int nse=i;
                    int ind=st.top();
                    st.pop();
                    int pse;
                    if(st.empty())  pse=-1;
                    else pse=st.top();
                    int width=nse-pse-1;
                    int area=heights[ind]*width;
                    ans=max(ans,area);
                }
                st.push(i);
            }
            while(!st.empty()){
                int nse=n;
                int pse;
                int ind=st.top();
                st.pop();
                if(st.empty()) pse=-1;
                else pse=st.top();
                int width=nse-pse-1;
                int area=heights[ind]*width;
                ans=max(ans,area);
            }
            cout<<ans<<endl;

        }   
        return ans;
    }
};