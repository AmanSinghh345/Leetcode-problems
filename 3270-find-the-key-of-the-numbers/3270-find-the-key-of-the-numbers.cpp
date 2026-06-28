class Solution {
public:
    int generateKey(int num1, int num2, int num3) {
        int n1=log10(num1)+1;
        int n2=log10(num2)+1;
        int n3=log10(num3)+1;
        string s1=to_string(num1);
        string s2=to_string(num2);
        string s3=to_string(num3);
        while(s1.size()<4){
            s1='0'+s1;
        }
        while(s2.size()<4) s2='0'+s2;
        while(s3.size()<4) s3='0'+s3;

        string ans;
        for(int i=0;i<4;i++){
            int a=s1[i]-'0';
            int b=s2[i]-'0';
            int c=s3[i]-'0';

            int mini=min({a,b,c});
            char ch =mini+'0';
            ans+=ch;
        }
        return stoi(ans);
    }
};