#include <bits/stdc++.h>

class Solution {
public:
    int subtractProductAndSum(int n) {
        string num=to_string(n);
        int sum=0,product=1;
       for(int i=0;i<num.size();i++){
        //converting to char 
        int digit=num[i]-'0';
        product*=digit;
        sum+=digit;
       }
       return (product-sum); 
    }
};