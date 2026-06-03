class Solution {
public:
    int digitFrequencyScore(int n) {
        vector<int> freq(10,0);
        while(n>0){
            int ld=n%10;
            n/=10;
            freq[ld]++;
        }
        int ans=0;
        for(int i=1;i<10;i++){
            ans+=(i*freq[i]);
        }
        return ans;
    }
};