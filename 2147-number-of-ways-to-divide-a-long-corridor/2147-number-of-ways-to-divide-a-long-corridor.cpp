class Solution {
public:
    int mod = 1e9 + 7;

    int numberOfWays(string corridor) {
        int seats = 0;
        for (char c : corridor)
            if (c == 'S') seats++;

    
        if (seats == 0 || seats % 2 != 0) return 0;

        long long ans = 1;
        int plantCnt = 0;
        int seatSeen = 0;

        for (char c : corridor) {
            if (c == 'S') {
                seatSeen++;
                if (seatSeen == 3) {
                    ans = (ans * (plantCnt + 1)) % mod;
                    plantCnt = 0;
                    seatSeen = 1; 
                }
            } 
            else if (seatSeen == 2) {
                plantCnt++;
            }
        }

        return ans;
    }
};
