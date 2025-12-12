class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
            int n=events.size();

            vector<int> ans(numberOfUsers,0);
        
            vector<pair<int,int>> user(numberOfUsers,{1,0});

            vector<pair<int,vector<string>>> event;

            for(int i=0;i<n;i++)
            {
                int id=stoi(events[i][1]);
                if(events[i][0]=="MESSAGE")
                {
                    events[i][0]="mESSAGE";
                }
                event.push_back({id,events[i]});
            }
            sort(event.begin(),event.end());

            for(int i=0;i<n;i++)
            {
                auto [id,data]=event[i];
                string mssg=data[0];
                int time=stoi(data[1]);
                string s=data[2];
              
                for(int i=0;i<user.size();i++)
                {
                    if(user[i].first!=1 and user[i].second<=time)
                    {
                        user[i].first=1;
                        user[i].second=0;
                    }
                }
                if(mssg=="OFFLINE")
                {
                    int us=stoi(s);
                    
                    user[us].first=0;
                    user[us].second=time+60;
                }
               else  if(mssg=="mESSAGE")
                {
                    if(s=="ALL")
                    {
                        for(int i=0;i<numberOfUsers;i++)
                        {
                            ans[i]=ans[i]+1;
                        }
                    }
                    else if(s=="HERE")
                    {
                        for(int i=0;i<numberOfUsers;i++)
                        {
                            if(user[i].first==1)
                            {
                                ans[i]=ans[i]+1;
                            }
                        }
                    }
                    else{
                       // string s=events[i][2];
                        for(int i=0;i<s.size();i++)
                        {
                            if(s[i]=='i')
                            {
                                i=i+2;
                                string num="";
                                while(i<s.size() and s[i]!=' ')
                                {
                                    num+=s[i];
                                    i++;
                                }
                                int us=stoi(num);
                                ans[us]=ans[us]+1;
                            }
                        }
                    }
                }
            }
            return ans;

    }
};