bool cmp(pair<int,int>& a,pair<int,int>& b){
        return (a.second-a.first)>(b.second-b.first);
     }
class Solution {
public:
   
    int minimumEffort(vector<vector<int>>& tasks) {
        int ans=0;
        vector<pair<int,int>> v;
        for(int i=0;i<(int)tasks.size();i++){
            ans+=tasks[i][0];
            v.push_back({tasks[i][0],tasks[i][1]});

        }
        sort(v.begin(),v.end(),cmp);
        int temp=ans;
        int cnt=0;
        for(auto & [c,m]:v){
            if(temp<m){
                cnt+=(m-temp);
                temp=m;
                
            }
            temp-=c;
        }
        return ans+cnt;
    }
};