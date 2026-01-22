class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans="";
        int i=num1.size()-1;
        int j=num2.size()-1;
        int carry=0;
        while(i>=0 or j>=0 )
        {
            int f,s;
            if(i>=0){
                f=num1[i]-'0';
                
            }
            else f=0;
            if(j>=0) {
                s=num2[j]-'0';
                
            }
            else s=0;
            int sum=f+s+carry;
            carry=sum/10;
            int put=sum%10;
            char c=put+'0';
            ans+=c;
            i--;
            j--;
        }
        if(carry!=0)
        ans+=to_string(carry);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};