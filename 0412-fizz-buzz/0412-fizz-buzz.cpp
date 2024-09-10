class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> arr(n,"");      
        for(int j=0;j<n;j++){
               int i=j+1;
               if(i%3==0 && i%5==0) 
                 arr[j]="FizzBuzz";
                 else if(i%3==0)
                 arr[j]="Fizz";
                 else if(i%5==0) 
                 arr[j]="Buzz";
                 else 
                 arr[j]=to_string(i);
        }
        return arr;
    }
};