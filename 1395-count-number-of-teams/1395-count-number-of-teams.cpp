class Solution {
public:
    int numTeams(vector<int>& ratings) {
        int cnt=0;
        int n=ratings.size();
        for(int i=0;i<n-2;i++)
        {
            for(int j=i+1;j<n-1;j++){
                if(ratings[j]<=ratings[i]) continue;
                for(int k=j+1;k<n;k++){
                    if(ratings[j]<ratings[k]) cnt++;
                }
            }
        }
          for(int i=0;i<n-2;i++)
        {
            for(int j=i+1;j<n-1;j++){
                if(ratings[j]>=ratings[i]) continue;
                for(int k=j+1;k<n;k++){
                    if(ratings[j]>ratings[k]) cnt++;
                }
            }
        }
        return cnt;
    }
};