class Solution {
public:
    bool checkPowersOfThree(int n) {
        while (n > 0) {
            if (n % 3 == 2) return false;  // If any ternary digit is 2, return false
            n /= 3;  // Move to the next ternary digit
        }
        return true;
    }
};
