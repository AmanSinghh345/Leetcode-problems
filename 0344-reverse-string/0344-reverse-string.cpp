class Solution {
public:
    void f(int i,int n,vector<char> & s){
       if (i >= n/2) return; // Base case
        swap(s[i], s[n-i-1]);
         f(i+1,n,s); // Recursive call
      

    }
    void reverseString(vector<char>& s) {
        int n=s.size();
       f(0,n,s);
    
    }
};