class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        stack<int> st;
        for(auto &it : asteroids){
            bool alive=true;
            if(st.empty()){ st.push(it); continue;}
            else if(it>0 ) st.push(it);
            else{
                while(!st.empty() && st.top()>0 && abs(it)>st.top()){
                    st.pop();
                }
                if(st.empty() || st.top()<0){ st.push(it); continue; }

                else if(st.top()>0 and st.top()>abs(it)){
                    alive=false;
                }
                else{
                    st.pop();
                    alive=false;
                }
            if(alive){
                st.push(it);
            }
            }

            
        }

        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};