class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        int n=arr.size();
        stack<int> st;
        for(int x:arr){
            bool destroyed=false;
            while(!st.empty() && st.top()>0 && x<0){
                if(st.top()==-x){
                    st.pop();
                    destroyed=true;
                    break;
                }
                else if(st.top()>-x){
                    destroyed=true;
                    break;
                }
                else{
                    st.pop();
                }
            }
            if(!destroyed) st.push(x);
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};