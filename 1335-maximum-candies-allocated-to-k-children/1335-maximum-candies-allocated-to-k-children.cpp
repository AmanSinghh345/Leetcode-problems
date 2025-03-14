class Solution {
public:
    bool isPossible(vector<int>& candies, long long k, int mid) {
        long long count = 0;
        for (int candy : candies) {
            count += (candy / mid);
            if (count >= k) return true;  // If we can already distribute enough
        }
        return count >= k;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        long long sum = accumulate(candies.begin(), candies.end(), 0LL);
        if (sum < k) return 0; // Not enough candies
        
        int low = 1, high = *max_element(candies.begin(), candies.end());
        int ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isPossible(candies, k, mid)) {
                ans = mid;  // Store the valid answer
                low = mid + 1;  // Try for larger packets
            } else {
                high = mid - 1;  // Reduce packet size
            }
        }
        return ans;
    }
};
