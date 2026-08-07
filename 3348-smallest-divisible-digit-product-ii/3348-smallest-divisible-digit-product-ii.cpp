#define ll long long 
class Solution {
public:
    string solve(ll req,int len){
        string res;
        for(int d=9;d>=2;d--){
            while(req%d==0){
                res.push_back(d+'0');
                req/=d;
            }
        }
        while(res.size()<len){
            res+='1';
        }
        reverse(res.begin(),res.end());
        return res;
    }
    string smallestNumber(string num, long long t) {
        int n=num.size();
        ll temp=t;
        vector<int> a={2,3,5,7};
        for(int i=0;i<a.size();i++){
            while(temp%a[i]==0) temp/=a[i];
        }
        if(temp!=1) return "-1";
        vector<long long > remain(n+1,t);
        for(int i=0;i<n;i++){
            int d=num[i]-'0';
            if(d==0) break;
            remain[i+1]=remain[i]/gcd(remain[i],(long long )d);
        }
        if(remain[n]==1) return num;

        int zeroIdx=n-1;
        if(num.find('0')!=-1) zeroIdx=num.find('0');

        for(int i=zeroIdx;i>=0;i--){
            ll req=remain[i];
            int free=n-i-1;

            for(int d=(num[i]-'0')+1;d<=9;d++){
                ll next=req/gcd(req,d);
                string reqNum=solve(next,free);

                if(reqNum.size()==free){
                    return num.substr(0,i)+char(d+'0')+reqNum;
                }
            }
        }
        return solve(t,n+1);
    }
};