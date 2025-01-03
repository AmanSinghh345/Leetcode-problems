class Solution {
public:
    bool hasGroupsSizeX(std::vector<int>& deck) {
        std::unordered_map<int, int> count;
        for (int card : deck) {
            count[card]++;
        }
        int g = -1;
        for (auto it = count.begin(); it != count.end(); ++it) {
            if (g == -1) {
                g = it->second;
            } else {
                g = std::gcd(g, it->second);
            }
        }
        return g >= 2;}};