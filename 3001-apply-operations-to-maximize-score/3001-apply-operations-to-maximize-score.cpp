class Solution {
private:
    int countPrimeFactors(int num) {
        int primeCount = 0;
        if (num % 2 == 0) {
            primeCount++;
            while (num % 2 == 0) {
                num /= 2;
            }
        }
        
        for (long long factor = 3; factor * factor <= num; factor += 2) {
            if (num % factor == 0) {
                primeCount++;
                while (num % factor == 0) {
                    num /= factor;
                }
            }
        }
        
        if (num > 1) primeCount++;
        return primeCount;
    }

    int powerMod(int base, int exponent, int mod) {
        long long result = 1;
        long long baseMod = base % mod;
        
        while (exponent > 0) {
            if (exponent & 1) {
                result = (result * baseMod) % mod;
            }
            baseMod = (baseMod * baseMod) % mod;
            exponent >>= 1;
        }
        
        return static_cast<int>(result);
    }

public:
    int maximumScore(vector<int>& arr, int limit) {
        int size = arr.size();
        if (size == 0) return 1;
        
        priority_queue<pair<int, int>> maxHeap;
        vector<int> nextGreater(size, size), prevGreater(size, -1), primeFactorCounts(size, 0);
        stack<int> forwardStack, backwardStack;
        
        for (int i = 0; i < size; i++) {
            primeFactorCounts[i] = countPrimeFactors(arr[i]);
            maxHeap.emplace(arr[i], i);
        }
        
        for (int i = 0; i < size; i++) {
            while (!forwardStack.empty() && primeFactorCounts[i] > primeFactorCounts[forwardStack.top()]) {
                nextGreater[forwardStack.top()] = i;
                forwardStack.pop();
            }
            forwardStack.push(i);
        }
        
        for (int i = size - 1; i >= 0; i--) {
            while (!backwardStack.empty() && primeFactorCounts[i] >= primeFactorCounts[backwardStack.top()]) {
                prevGreater[backwardStack.top()] = i;
                backwardStack.pop();
            }
            backwardStack.push(i);
        }
        
        int resultScore = 1;
        const int MODULO = 1000000007;
        
        while (!maxHeap.empty() && limit > 0) {
            auto [value, index] = maxHeap.top();
            maxHeap.pop();
            
            long long rangeCount = 1LL * (nextGreater[index] - index) * (index - prevGreater[index]);
            long long stepsToTake = min(rangeCount, static_cast<long long>(limit));
            
            int multiplier = powerMod(value, static_cast<int>(stepsToTake), MODULO);
            resultScore = static_cast<int>((1LL * resultScore * multiplier) % MODULO);
            
            limit -= stepsToTake;
        }
        
        return resultScore % MODULO;
    }
};
