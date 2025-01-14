class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
     int n=A.size();
     vector<int> C(n,0);
     set<int> s1;
     set<int> s2;
     for(int i=0;i<n;i++){
        if(s1.find(A[i])!=s1.end()) C[i]++;
        else    s2.insert(A[i]);
        
        if(s2.find(B[i])!=s2.end()) C[i]++;
        else 
            s1.insert(B[i]);
         
       
     }   
     for(int i=1;i<n;i++){
            C[i]+=C[i-1];
     }
     return C;
    }
};