class Solution {
public:
    string getPermutation(int n, int k) {
        int fact = 1;
        vector<int> num;
        for (int i = 1; i < n; i++) {
            fact *= i;
            num.push_back(i);
        }
        // Add the last number to the list
        num.push_back(n);
        // Initialize the answer string
        string ans = "";
        // Convert k to 0-based index
        k--;
        while (true) {
            // Add the appropriate number to the answer
            ans += to_string(num[k / fact]);
            // Remove the used number from the list
            num.erase(num.begin() + k / fact);
            if (num.size() == 0) 
                break;
       
            k = k % fact;
            // Update factorial to reflect the remaining numbers
            fact = fact / num.size();
        }
        return ans;
    }
};
