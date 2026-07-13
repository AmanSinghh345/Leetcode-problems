class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        string s="123456789";
        for(int len=2;len<=9;len++){
            for(int i=0;i+len<=9;i++){
                int val=stoi(s.substr(i,len));
                if(val>=low && val<=high) ans.push_back(val);
            }
        } 
       return ans;
    }
};