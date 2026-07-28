class Solution {
public:
    string smallestPalindrome(string s) {
        int n=s.size();
        vector<int> freq(26,0);
        for(char c:s) freq[c-'a']++;

        for(int x: freq) cout<<x<<" ";
        cout<<endl;
        bool foundOdd=false;
        char ch;
        string ans="";
        string left="",right="";
        for(int i=0;i<26;i++){
            if(freq[i]==0) continue;
            if(freq[i]&1) {
                foundOdd=true;
                ch='a'+i;
            }

                int half=freq[i]/2;
         
                string temp=string(half,'a'+i);
              
                cout<<temp<<endl;;
                left=left+temp;
                right=temp+right;

     
            
        }
        if(foundOdd){
            left+=ch;
        }
         ans=left+right;
        return ans;
    }
};