class Solution {
public:
    void f(int l,int r,vector<char> & s){
       if (l >= r) return; // Base case
        swap(s[l], s[r]);
         f(l + 1, r - 1, s); // Recursive call
      

    }
    void reverseString(vector<char>& s) {
        int n=s.size();
       f(0,n-1,s);
    
    }
};