class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int ans=0;
        sort(reservedSeats.begin(),reservedSeats.end());
        int i=0;
        int unique=0;
       while(i<reservedSeats.size()){
            int cnt=0;
            int val=reservedSeats[i][0];
            bool f1=true,f2=true,f3=true;
             while(i<reservedSeats.size() and reservedSeats[i][0]==val){
                int x=reservedSeats[i][1];
                if(x==2 or x==3) f1=false;
                else if(x==4 or x==5) {
                    f1=false;
                    f2=false;
                }
                else if(x==6 or x==7){
                    f2=false;
                    f3=false;
                }
                else if(x==8 or x==9){
                    f3=false;
                }
                i++;
             }
             unique++;
             if(f1 and f3) cnt=2;
             else if(f1 or f2 or f3) cnt=1;
             ans+=cnt;
        }
        ans+=(n-unique)*2;
        return ans;
    }
};