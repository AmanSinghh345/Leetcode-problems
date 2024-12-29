class Solution {
    #define ll long long

    int memoization[1001][1001];
    int MODULO = 1000000007;
    int targetLength;
    int wordLength;
    int wordCount;
    vector<vector<int>> characterFrequency;

    int countWays(vector<string>& words, int wordIndex, string& target, int targetIndex) {
        if (targetIndex == targetLength) // Match complete
            return wordIndex <= wordLength;
        if (wordIndex >= wordLength || (wordLength - wordIndex < targetLength - targetIndex)) // No match or insufficient size
            return 0;
        if (memoization[wordIndex][targetIndex] != -1) // Repeating sub-problem
            return memoization[wordIndex][targetIndex];

        char currentChar = target[targetIndex];

        ll waysWithoutMatching = countWays(words, wordIndex + 1, target, targetIndex);
        ll waysWithMatching = countWays(words, wordIndex + 1, target, targetIndex + 1) % MODULO;
        ll totalWays = (waysWithoutMatching + (ll)characterFrequency[wordIndex][currentChar - 'a'] * waysWithMatching) % MODULO;

        return memoization[wordIndex][targetIndex] = totalWays;
    }

public:
    int numWays(vector<string>& words, string target) {
        targetLength = target.size();
        wordLength = words[0].size();
        wordCount = words.size();
        characterFrequency = vector<vector<int>>(wordLength, vector<int>(26, 0));

        // Calculate character frequency for each position
        for (int i = 0; i < wordCount; ++i) {
            for (int j = 0; j < wordLength; ++j) {
                char currentChar = words[i][j];
                characterFrequency[j][currentChar - 'a']++;
            }
        }

        memset(memoization, -1, sizeof(memoization));
        return countWays(words, 0, target, 0);
    }
};
