class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int cnt=0;
        for(int i=num1;i<=num2;i++){
            string val=to_string(i);
            if(val.size()<3) continue;
            for(int j=1;j<val.size()-1;j++){
                if(val[j]>val[j-1] && val[j]>val[j+1]) cnt++;
                else if(val[j]<val[j-1] && val[j]<val[j+1]) cnt++;
            }
        }
        return cnt;
    }
};