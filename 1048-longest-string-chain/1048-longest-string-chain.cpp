class Solution {
public:
    bool compare(string a,string b){
        if(abs((int)a.size()-(int)b.size())!=1) return false;
        if(a.size()>b.size()){
            string temp=b;
            b=a;
            a=temp;
        }
        int i=0,j=0;
        int cnt=0;
        while(i<(int)a.size() && j<(int)b.size()){
            if(a[i]!=b[j]){
                cnt++;
                j++;
            }
            else{
                i++;
                j++;
            }

        }
        if(cnt>1) return false; 
        return true;
    }
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        sort(words.begin(), words.end(), [](const string& a, const string& b){
        return a.size() < b.size();   // sort by length — predecessor always comes first
    });
        vector<int> dp(n,1);
        int maxi=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(compare(words[i],words[j]) && dp[j]+1>dp[i])
                    dp[i]=dp[j]+1;
            }
            maxi=max(maxi,dp[i]);
        }
        return maxi;
    }
};