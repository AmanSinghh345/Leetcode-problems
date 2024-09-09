class Solution {
public:
   int add(int num){
    string s=to_string(num);
    int sum=0;
     for(int i=0;i<s.size();i++){
                 sum=sum+(s[i]-'0');         
        }
        string str=to_string(sum);
        if(str.size()==1)
     return sum;
     else return add(sum);

   }
    int addDigits(int num) {
        
        
   return add(num);
    
        
    }
};

   
 