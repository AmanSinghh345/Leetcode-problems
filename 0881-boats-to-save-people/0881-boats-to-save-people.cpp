class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int n=people.size();
        int cnt=0;
        int l=0,r=n-1;
        while(l<=r){
            if(people[l]+people[r]<=limit){
               l++;
            }
            r--;
            cnt++;
        }
        return cnt;
    }
};