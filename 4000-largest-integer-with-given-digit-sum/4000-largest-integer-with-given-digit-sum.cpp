class Solution {
public:
    int largestInteger(int n, int s) {
        
        for(int i=pow(10,n)-1;i>=0;i--){
            string p=to_string(i);
            int sum=0;
            for(char c:p){
                sum+=(c-'0');
            }
            if(sum==s) return i;
        }
        return -1;
    }
};