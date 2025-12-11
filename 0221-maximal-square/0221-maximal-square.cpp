class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
         int n = matrix[0].size();
        int m = matrix.size();
        vector<int> heights(n, 0);
        int maxi = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '0')
                    heights[j] = 0;
                else
                    heights[j]++;
            }
            // Now this have become a single largest area in histogram problem
            // so  find nse and pse and apply formula area=
            // heights[i]*(nse-pse-1)

            vector<int> nse(n,n);
            stack<int> st;
            for(int a=n-1;a>=0;a--)
            {
                while(!st.empty() and heights[st.top()]>=heights[a])
                {
                    st.pop();
                }
                if(st.empty()) nse[a]=n;
                else nse[a]=st.top();
                st.push(a);
            }

            vector<int> pse(n,-1);
            stack<int> stt;
            for(int b=0;b<n;b++)
            {

                while(!stt.empty() and heights[stt.top()]>=heights[b])
                {
                    stt.pop();
                }
                if(!stt.empty()) pse[b]=stt.top();
                stt.push(b);
            }

            for(int c=0;c<n;c++)
            {   
                int width = nse[c] - pse[c] - 1;
    int side = min(width, heights[c]);
    maxi = max(maxi, side * side);
            }


        }
        return maxi;
    }
};