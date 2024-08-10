class Solution {
public:
    bool rotateString(string s, string goal) {
         int n=s.length();
        
        queue<char> q1;
        queue<char> q2;
        for(int i=0;i<n;i++){
            q1.push(s[i]);

        }
        for(int i=0;i<goal.length();i++){
            q2.push(goal[i]);
        }
        int k=goal.length()-1;
    while(k!=0){
        if(q1==q2) return true;
        char ch=q2.front();
        q2.pop();
        q2.push(ch);
        if(q1==q2)
        return true;
        k--;
      
   
         }
       
        return false; 
    }
};