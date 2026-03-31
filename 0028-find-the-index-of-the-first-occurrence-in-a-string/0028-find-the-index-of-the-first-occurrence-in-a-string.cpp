class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=haystack.size();
        int m=needle.size();
      
        for(int i=0;i<n;i++){
            int ind=i;
            bool f=true;
            for(int j=0;j<m;j++){
                if(haystack[ind]==needle[j]){
                    ind++;
                }
                else {
                    f=false;}
            }
            if(f)
            return i;
        }
        return -1;
    }
};