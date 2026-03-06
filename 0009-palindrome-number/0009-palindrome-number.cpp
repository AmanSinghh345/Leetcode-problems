class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0 or (x!=0 and x%10==0)) return false; // handle negative and ending zero case
        int rev=0;
        while(x>rev)
        {
            rev=rev*10+x%10;
            x/=10;
        }
        if(x==rev || x==rev/10) return true;
        return false;
    }
};