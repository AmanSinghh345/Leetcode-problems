class Solution {
public:
    vector<int> vowelStrings(vector<string>& words,
                             vector<vector<int>>& queries) {
        int n = queries.size();
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        vector<int> ans;
        vector<int> prefix;
        int prefix_sum = 0;

        for (int i = 0; i < words.size(); i++) {
            int first = 0;
            int last = words[i].size() - 1;
            if (vowels.find(words[i][first]) != vowels.end() &&
                vowels.find(words[i][last]) != vowels.end()) {
                prefix_sum++;
            }
            prefix.push_back(prefix_sum);
        }


        for (int i = 0; i < n; i++) {
            int left = queries[i][0];
            int right = queries[i][1];

            int temp = prefix[right];
            if (left > 0) {
                temp -= prefix[left - 1];
            }

            ans.push_back(temp);
        }

        return ans;
    }
};