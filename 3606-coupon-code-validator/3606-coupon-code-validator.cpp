class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int n=code.size();
        vector<vector<string>> ans(4);
        for(int i=0;i<n;i++)
        {
            bool ok=true;
            string s=code[i];
            if(s.size()==0) continue;
            for(int j=0;j<s.size();j++)
            {
                
                if((s[j]>='a' and s[j]<='z') or (s[j]>='A' and s[j]<='Z') or (s[j]>='0' and s[j]<='9') or (s[j]=='_'))
                {
                    continue;
                }
                else 
                {
                    ok=false;
                    break;
                }
            }
            if(ok and isActive[i])
            {
                
                string x=businessLine[i];
                
                    if(x=="electronics")
                    {   
                        ans[0].push_back(code[i]);
                    }
                    else if(x=="grocery")
                    {
                        ans[1].push_back(code[i]);
                    }
                    else if(x=="pharmacy")
                    {
                        ans[2].push_back(code[i]);
                    }
                    else if(x=="restaurant")
                    {
                        ans[3].push_back(code[i]);
                    }
                    else continue;
                }
        }
        vector<string> res;
        for(int i=0;i<ans.size();i++)
        {
            vector<string> a=ans[i];
            sort(a.begin(),a.end());
            for(int j=0;j<a.size();j++)
            {
                res.push_back(a[j]);
            }
        }
        return res;
    }
};