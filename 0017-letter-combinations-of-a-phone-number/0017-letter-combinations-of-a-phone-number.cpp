class Solution {
public:
    void find(int i,string &ds,vector<string>& ans,string& digits,vector<string>& phone){
        
       
        //base case 
        if(i==digits.size()){
            ans.push_back(ds);
            return ;
        }

        
         int d=digits[i]-'0';// char to int

         for(int j=0;j<phone[d].size();j++){
        ds.push_back(phone[d][j]);
        find(i+1,ds,ans,digits,phone);
        ds.pop_back();
         }

    }
    vector<string> letterCombinations(string digits) {
        
        vector<string> phone(10);
        phone[2]="abc";
        phone[3]="def";
        phone[4]="ghi";
        phone[5]="jkl";
        phone[6]="mno";
        phone[7]="pqrs";
        phone[8]="tuv";
        phone[9]="wxyz";

        vector<string> ans;
        string ds;
        find(0,ds,ans,digits,phone);

        return ans;

    }
};