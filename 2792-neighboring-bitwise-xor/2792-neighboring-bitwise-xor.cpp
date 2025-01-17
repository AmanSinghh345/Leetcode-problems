class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n=derived.size();
        int i=0;
        vector<int> A(n);
        vector<int> B(n);
        if(n==1 && derived[0]!=1) return true; 
        if(n==1 && derived[0]==1) return false;
        if(derived[i]==0 ){
            A[i]=0;
            A[i+1]=0;
            B[i]=1;
            B[i+1]=1;
        }
        else {
           A[i]=0;
           A[i+1]=1;
           B[i]=1;
           B[i+1]=0; 
        }
        i++;
        while(i<n-1){
            if(derived[i]==0 ){
                if(A[i]==0) A[i+1]=0;
                if(A[i]==1) A[i+1]=1;
                if(B[i]==0) B[i+1]=0;
                if(B[i]==1) B[i+1]=1;
            }
            else {
                 if(A[i]==0) A[i+1]=1;
                if(A[i]==1) A[i+1]=0;
                if(B[i]==0) B[i+1]=1;
                if(B[i]==1) B[i+1]=0;
            }
            i++;
        }
        if(A[0]^A[n-1]==derived[n-1]) return true;
        return false;
    }
};