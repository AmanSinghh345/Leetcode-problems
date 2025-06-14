class Solution {
public:
    int minMaxDifference(int num) {
        // string maxi="";
        // string mini="";
        // string nums=to_string(num);
        // int n=nums.size();
        //     int temp=num;
        //     char first=nums[0];
        //     char maxfirst;
        //     for(int i=0;i<n;i++){
        //         if(nums[i]!=9){
        //             maxfirst=nums[i];
        //             break;
        //         }
        //     }
        //     for(int i=0;i<n;i++){
        //         if(nums[i]==maxfirst){
        //             maxi+='9';
        //         }
        //         else {
        //             maxi+=nums[i];
        //         }
        //         if(nums[i]==first){
        //             mini+='0';
                    
        //         }
        //         else {
        //             mini+=nums[i];
        //         }
        //     }
        //     int a=stoi(maxi);
        //     int b=stoi(mini);
        //     int ans=a-b;
        //     return ans;
        string s=to_string(num);
        int n=s.size();
        //for mini
        char c=s[0];
        string mini="";
        for(int i=0;i<n;i++){
            if(s[i]==c){
                mini+='0';
            }
            else mini+=s[i];
        }
        int b=stoi(mini);
        //for maxi
        string maxi="";
        for(int i=0;i<n;i++){
            if(s[i]!='9'){
                c=s[i];
                break;
            } 
        }
        for(int i=0;i<n;i++){
            if(s[i]==c){
                maxi+='9';
            }
            else maxi+=s[i];
        }
        int a=stoi(maxi);
        return a-b;

    }
};