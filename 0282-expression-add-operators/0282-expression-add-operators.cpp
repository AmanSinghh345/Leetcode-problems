class Solution {
public:
    void find(string& s,int& target,int pos,long long  currVal,long long prev,string ds,vector<string>& ans){

        //base case 
        if(pos==s.size()){
            if(currVal==target){
                ans.push_back(ds);
                return;
            }
        }

        for(int len=1;len<=s.size()-pos;len++){
            string part=s.substr(pos,len);
            long long num=stoll(part);

            if(part.size()>1 and part[0]=='0') break;

            if(pos==0){
                find(s,target,pos+len,num,num,part,ans);
            }
            else{
                //place + 
                find(s,target,pos+len,currVal+num,num,ds+"+"+part,ans);
                //place -
                find(s,target,pos+len,currVal-num,-num,ds+"-"+part,ans);
                //place * 
                find(s,target,pos+len,currVal-prev+prev*num,prev*num,ds+"*"+part,ans);
            }

        }

    }
    vector<string> addOperators(string num, int target) {
        vector<string> ans;

        find(num,target,0,0,0,"",ans);
        return ans;
    }
};