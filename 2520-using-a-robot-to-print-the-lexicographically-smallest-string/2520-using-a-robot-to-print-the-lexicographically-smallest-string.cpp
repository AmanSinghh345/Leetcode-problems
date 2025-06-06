class Solution {
public:
    string robotWithString(string s) {
        int n = s.size();
    vector<char> min_suffix(n); // min_suffix[i] = min char from s[i..n-1]
    
    min_suffix[n - 1] = s[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        min_suffix[i] = min(s[i], min_suffix[i + 1]);
    }
    
    stack<char> st;
    string result = "";
    
    for (int i = 0; i < n; ++i) {
        st.push(s[i]);
        // Keep popping while top of stack is <= the min suffix
        while (!st.empty() && st.top() <= min_suffix[i + 1 >= n ? n - 1 : i + 1]) {
            result += st.top();
            st.pop();
        }
    }
    
    // Add remaining characters in stack
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }
    
    return result;
}
    
};