class Solution {
public:
    int minDistance(string word1, string word2) {
        
        int m=word1.size();
        int n=word2.size();
        vector<int> prev(n+1,0),curr(n+1,0);
      
        for(int j=0;j<=n;j++){
            prev[j]=n-j;
        }
        for(int i=m-1;i>=0;i--){
            curr[n]=m-i;
            for(int j=n-1;j>=0;j--){
                if(word1[i]==word2[j]){
                    curr[j]=prev[j+1];
                }
                else{
                    curr[j]=min({1+prev[j],1+curr[j+1],1+prev[j+1]}); // delete , replace , insert 
                }
            }
            prev=curr;
        }
        return prev[0];
    }
};