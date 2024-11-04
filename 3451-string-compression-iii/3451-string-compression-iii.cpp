class Solution {
public:
    string compressedString(string word) {
        string comp = "";
        int cnt = 1; // Start counting from 1 since the first character is already counted
        int n = word.size();
        for (int i = 1; i < n; i++) {
                  if(cnt==9){
                comp +=to_string(cnt)+word[i-1];
                cnt=1;
            
            }
           else if (word[i] == word[i - 1]) {
                cnt++;
            }
      
            
             else {
                comp +=  to_string(cnt) + word[i-1];
                cnt = 1;
            }
        }
        comp +=  to_string(cnt) + word[n-1]; // Append the last segment
        return comp;
    }
};
