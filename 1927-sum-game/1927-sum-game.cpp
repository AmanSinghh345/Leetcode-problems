class Solution {
public:
    bool sumGame(string num) {
        int n=num.size();
        string f=num.substr(0,n/2);
        string s=num.substr(n/2,n/2);
        long long  sum1=0,sum2=0,m1=0,m2=0;
        for(char c:f){
            if(c=='?') {
                m1++;
                continue;
            }
            sum1+=(c-'0');
        }
        for(char c:s){
            if(c=='?'){
                m2++;
                continue;
            }
            sum2+=(c-'0');
        }
        cout<<sum1<<" "<<sum2<<endl;
        cout<<m1<<" "<<m2<<endl;
        if((m1+m2)&1) return true;
       if(sum1-sum2==((m2-m1)/2 ) *9) return false;
       return true;
    }
};