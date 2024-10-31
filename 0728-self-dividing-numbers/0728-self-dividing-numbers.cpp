class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        
        for(int i=left;i<=right;i++){
            bool flag=true;
            string str=to_string(i);
            for(char c:str){
                int digit=c-'0';
                if(digit==0 || i%digit!=0){
                    flag=false;
                    break;
                }
            }
            if(flag) ans.push_back(i);
        }
        return ans;
    }
};