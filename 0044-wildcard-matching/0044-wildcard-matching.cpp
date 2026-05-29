class Solution {
public:
    bool find(int i,int j,string& a,string& b,int n1,int n2,vector<vector<int>>& dp){
        //base case 
        if(i==0 && j==0) return true;
        if(i==0 && j>0) return false;
        if(i>0 && j==0) {
            while(i>0){
                if(a[i-1]!='*') return false;
                i--;
            }
            return true;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        bool res;
        if(a[i-1]==b[j-1] || a[i-1]=='?')   res= find(i-1,j-1,a,b,n1,n2,dp);
        else if(a[i-1]=='*') res= find(i,j-1,a,b,n1,n2,dp) || find(i-1,j,a,b,n1,n2,dp);
        else res=false;
        return dp[i][j]=res;
    }
    bool isMatch(string s, string p) {
        int n1=p.size();
        int n2=s.size();
        string a=p;
        string b=s;
        
       
        vector<bool> dp(n2+1,false);
        int rowFlag;
        for(int i=1;i<=n1;i++){
            if(a[i-1]=='*') rowFlag=i;
            else break;
        }
        dp[0]=true;
        for(int i=1;i<=n1;i++){
            bool prev=dp[0];
               dp[0]= i<=rowFlag ? true : false;
            for(int j=1;j<=n2;j++){
                bool temp=dp[j];
                if(a[i-1]==b[j-1] || a[i-1]=='?') dp[j]=prev;
                else if(a[i-1]=='*') dp[j]=dp[j-1] || temp;
                else dp[j]=false;
                prev=temp;
            }
            
        }
        return dp[n2];
    }
};