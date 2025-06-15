class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        int n = s.size();
        // maxi
        char f;
        if (s[0] == '9') {
            for (int i = 0; i < n; i++) {
                if (s[i] != '9') {
                    f = s[i];
                    break;
                }
            }

        }
         else{
            f = s[0];}
        string maxi = "";
        for (int i = 0; i < n; i++) {
            if (s[i] == f)
                maxi += '9';
            else
                maxi += s[i];
        }
        int a = stoi(maxi);

        // mini;
        char c;
        string mini = "";
        if (s[0] == '1') {
            for (int i = 0; i < n; i++) {
                if (s[i] != '1' and s[i]!='0') {
                    c = s[i];
                    break;
                }
            }
            for (int i = 0; i < n; i++) {
                if (s[i] == c)
                    mini += '0';
                else
                    mini += s[i];
            }

        } else {
            c = s[0];
            for (int i = 0; i < n; i++) {
                if (s[i] == c)
                    mini += '1';
                else
                    mini += s[i];
            }
        }
        int b = stoi(mini);
        return a - b;
    }
};