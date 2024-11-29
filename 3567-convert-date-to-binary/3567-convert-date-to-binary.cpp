class Solution {
public:
     string convert(int num){
        string s;
        while(num){
            s+=to_string(num%2);
            num/=2;
        }
        reverse(s.begin(),s.end());
        return s;
     }
    string convertDateToBinary(string date) {
       string ans;
       string temp;
       for(auto it:date){
        if(it=='-'){
            ans+=convert(stoi(temp));
            ans+="-";
            temp="";
        }
        else{
            temp+=it;
        }
       }
       ans+=convert(stoi(temp));
       return ans;
    }
};