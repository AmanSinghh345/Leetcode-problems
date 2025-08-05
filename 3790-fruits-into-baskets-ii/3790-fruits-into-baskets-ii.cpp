class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int cnt=0;
        int n=baskets.size();
        for(auto it:fruits ){
            int flag=1;
            for(int i=0;i<n;i++){
                if(it<=baskets[i]){
                    baskets[i]=0;
                    flag=0;
                    break;
                }
            }
            cnt+=flag;
        }
        return cnt;
    }
};