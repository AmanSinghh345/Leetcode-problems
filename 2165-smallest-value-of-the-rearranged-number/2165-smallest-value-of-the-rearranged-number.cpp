class Solution {
public:
    long long smallestNumber(long long num) {
        vector<int> freq(10,0);
        if(num==0) return 0;
        bool sign=true;
        if(num<0) sign=false;
        num=abs(num);
        while(num>0){
            int ld=num%10;
            freq[ld]++;
            num/=10;
        }

        string s="";
        if(freq[0] && sign){
            for(int i=1;i<10;i++){
                if(freq[i]){
                    s+=(i+'0');
                    freq[i]--;
                    break;
                }
            }   
        }
        if(sign){
        for(int i=0;i<10;i++){
            while(freq[i]){
                s+=(i+'0');
                freq[i]--;
            }
        }
        }
        else {
            for(int i=9;i>=0;i--){
                while(freq[i]){
                    s+=(i+'0');
                    freq[i]--;
                }
            }
        }

        long long  ans=stol(s);
        return sign?ans:-ans;
   
    }
};