class Solution {
public:
    long long countCommas(long long n) {
        string s=to_string(n);
        if(s.size()<4) return 0;
        long long num=n/3;
        long long ans=0;
        string p2="999";
        string prev="999999";
        long long i=1;
        while(stoll(p2)<=n){
            cout<<stoll(prev)<<" "<<stoll(p2)<<endl;
            if(n<stoll(prev)){
                ans+=i*(n-stoll(p2));
            }
            else{
                ans+=i*(stoll(prev)-stoll(p2));
            }
            cout<<ans<<endl;
            p2=prev;
            prev+="999";
            i++;
        }
        return ans;
    }
};