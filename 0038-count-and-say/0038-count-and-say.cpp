class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        string prev="1";
        
        n-=1;
        while(n--){
        string curr="";
        char last=prev[0];
        int cnt=1;
        for(int i=1;i<prev.size();i++){
            if(last==prev[i]) cnt++;
            else {
                curr+=(to_string(cnt) + string(1,last));
                last=prev[i];
                cnt=1;
            }
        }
        curr+=(to_string(cnt)+string(1,last));
        prev=curr;
        }
        return prev;
    }
};