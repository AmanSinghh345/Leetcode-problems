class Solution {
public:
    vector<int> lexicalOrder(int n) {
       vector<int> ans;
       int one=1;
       for(int i=0;i<n;i++){
          ans.push_back(one);
          if(one*10<=n) one*=10;
          else{
            while(one>=n or one%10==9)
                one/=10;
            one++;
          }
       }
       return ans;
    }
};