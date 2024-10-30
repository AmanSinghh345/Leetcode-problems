class Solution {
public:
    int minimumSum(int num) {
        vector<long> arr(4);
        int i=0;
        int rem;
       while(num>0){
          rem=num%10;
          num=num/10;
           arr[i]=rem;
           i++;
       }
       sort(arr.begin(),arr.end());

       return (((arr[0]*10)+arr[3]) + ((arr[1]*10)+arr[2]));
    }
};