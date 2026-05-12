class Solution {
public:
    string removeKdigits(string num, int k) {
            int n=num.size();
        
            string st="";
            for(int i=0;i<n;i++){
                while(!st.empty() && k>0 &&st.back()>num[i]){
                    st.pop_back();
                    k--;
                }
                st.push_back(num[i]);
            }   
            while(k>0 && !st.empty()){
                st.pop_back();
                k--;
            }
            int i=0;
            while(i<st.size() && st[i]=='0'){
                i++;
            }
            string ans=st.substr(i);
            return ans.empty()?"0":ans;
    }
};