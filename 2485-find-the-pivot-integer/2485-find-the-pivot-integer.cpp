class Solution {
public:
    int pivotInteger(int n) {
        int x=round(sqrt((n*(n+1))/2));
        if(x*x==(n*(n+1))/2) return x;
        return -1;
    }
};