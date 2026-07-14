class Solution {
public:
    int countDifferentSubsequenceGCDs(vector<int>& nums) {
            int max_gcd=0;
            for(int x:nums) max_gcd=max(max_gcd,x);

            vector<bool> freq(max_gcd+1,false);
            for(int x:nums) freq[x]=true;

            int cnt=0;
            for(int gccd=1;gccd<=max_gcd;gccd++){
                int curr_gcd=0;
                for(int mul=gccd;mul<=max_gcd;mul+=gccd){
                    if(freq[mul]) curr_gcd=gcd(curr_gcd,mul);

                    if(curr_gcd==gccd) {
                        cnt++;
                        break;
                    }
                }
            }
            return cnt;
    }
};