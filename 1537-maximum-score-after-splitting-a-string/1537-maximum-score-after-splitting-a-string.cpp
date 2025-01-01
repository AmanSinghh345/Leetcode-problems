class Solution {
public:
    int maxScore(string s) {
        int n=s.size();
        int maxi=INT_MIN;
        int count0=0,count1=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0') count0++;
            else count1++;
        }
        for(int i=0;i<n-1;i++){
            string left=s.substr(0,i+1);
            string right=s.substr(i+2);
            int cnt0=0,cnt1=0,score=0;
            for(int j=0;j<left.size();j++){
                if(s[j]=='0') cnt0++;
                else cnt1++;
               
                    
            }
             score=cnt0+(count1-cnt1);
             maxi=max(maxi,score);
        } 

    return maxi;
    }
};