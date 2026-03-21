class Solution {
public:
    //pos , prev , dir,tight, started , sum
    long long  dp[20][11][4][2][2][140];
    string a;
    bool isGood(long long  x){
        string s=to_string(x);
        bool inc=true,dec=true;
        for(int i=1;i<s.size();i++){
            if(s[i-1]>=s[i]) inc=false;
            if(s[i-1]<=s[i]) dec=false;

        }
        return inc || dec;
    }
    /*
    dir=0 not decided
    dir=1 increasing
    dir=2 decreasing
    dir=3 not a monotone
    */
    long long  solve(int pos,int prev,int dir,int tight,int started,int sum){
        if(pos==a.size()){
            if(!started) return 0;
            if(dir==1 || dir==2 || dir==0) return 1;

            
                if(isGood(sum)) return 1;
                else return 0;
            

        }
        if( dp[pos][prev][dir][tight][started][sum]!=-1) return  dp[pos][prev][dir][tight][started][sum];
        long long  res=0;
        int limit=tight?a[pos]-'0':9;
        for(int d=0;d<=limit;d++){
            int nstarted=started || (d!=0);
            int ntight=tight && (d==limit);

            if(!nstarted){
                res+=solve(pos+1,10,0,ntight,0,0);
            }
            else {
                if(!started) res+=solve(pos+1,d,0,ntight,1,d);
                else {
                    int ndir=dir;
                    if(dir==0){
                        if(prev<d) ndir=1;
                        else if(prev>d) ndir=2;
                        else ndir=3;
                    }
                    else if(dir==1){
                        if(prev<d) ndir=1;
                        else ndir=3;
                    }
                    else if(dir==2){
                        if(prev>d) ndir=2;
                        else ndir=3;
                    }
                    else  ndir=3;


                     res+=solve(pos+1,d,ndir,ntight,1,sum+d); 
                }
               
            }
        }
       return dp[pos][prev][dir][tight][started][sum]=res;
    }
    long long count(long long  x){

        a=to_string(x);
        memset(dp,-1,sizeof(dp));
        long long ans=solve(0,10,0,1,0,0);
        return ans;
    }
    long long countFancy(long long l, long long r) {
        return count(r)-count(l-1);
    }
};