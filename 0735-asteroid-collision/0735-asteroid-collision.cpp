class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        int n=arr.size();
        stack<int> st;
        vector<int> left(n,1);
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[i]<0)
            {
                if(arr[st.top()]<abs(arr[i])) {
                    left[st.top()]=0;
                    st.pop();
                }
                else if(arr[st.top()]==abs(arr[i])){
                    left[st.top()]=0;
                    left[i]=0;
                    st.pop();
                    break;
                }
                else{
                    left[i]=0;
                    break;
                }
            }
            if(arr[i]>0) st.push(i);
            
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(left[i]) ans.push_back(arr[i]);
        }
        return ans;
    }
};