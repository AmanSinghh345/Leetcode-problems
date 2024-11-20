class Solution {
public:
    int takeCharacters(string str, int k) {
        int len = str.size();
        int left = 0, right = 0;
        int result = len; 
        int countA = 0, countB = 0, countC = 0;

        // Count total occurrences of 'a', 'b', and 'c'
        int totalA = 0, totalB = 0, totalC = 0;
        for (char ch : str) {
            if (ch == 'a') totalA++;
            else if (ch == 'b') totalB++;
            else if (ch == 'c') totalC++;
        }

        // If there are not enough 'a', 'b', or 'c'
        if (totalA < k || totalB < k || totalC < k) {
            return -1;
        }

        // Reset counters and start sliding window
        countA = 0, countB = 0, countC = 0;
        while (right < len) {
            if (str[right] == 'a') countA++;
            if (str[right] == 'b') countB++;
            if (str[right] == 'c') countC++;
            right++;

            // Shrink window if it exceeds the limits
            while (countA > totalA - k || countB > totalB - k || countC > totalC - k) {
                if (str[left] == 'a') countA--;
                if (str[left] == 'b') countB--;
                if (str[left] == 'c') countC--;
                left++;
            }

            // Update the answer with the minimum number of characters to remove
            result = min(result, len - (right - left));
        }

        return result;
    }
};
