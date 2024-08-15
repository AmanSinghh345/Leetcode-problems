class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string com="";
        int i=0;
        int n1=word1.length();
        int n2=word2.length();
        while(i<n1 || i<n2){
            if(i<n1)
            com+=word1[i];
            if(i<n2)
            com+=word2[i];
            i++;
        }
return com;
    }
};