class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        unordered_map<int, unordered_set<int>> stoneJumpMap;

        for (int stone : stones) {
            stoneJumpMap[stone] = unordered_set<int>();
        }
        
        stoneJumpMap[stones[0]].insert(1);

        for (int i = 0; i < n; i++) {
            int stone = stones[i];
            for (int jumpSize : stoneJumpMap[stone]) {
                int nextStone = stone + jumpSize;

                if (nextStone == stones[n-1]) {
                    return true;
                }
                
                if (stoneJumpMap.find(nextStone) != stoneJumpMap.end()) {
                    if (jumpSize - 1 > 0) {
                        stoneJumpMap[nextStone].insert(jumpSize - 1);
                    }
                    stoneJumpMap[nextStone].insert(jumpSize);
                    stoneJumpMap[nextStone].insert(jumpSize + 1);
                }
            }
        }

        return false;
    }
};
