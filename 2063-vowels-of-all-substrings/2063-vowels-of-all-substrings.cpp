class Solution {
public:
    long long countVowels(string word) {
        int n=word.size();
        long long cnt=0;
        for(int i=0;i<n;i++){
            if(word[i]=='a' || word[i]=='e' || word[i]=='i' || word[i]=='o' or word[i]=='u'){
                long long left=i+1;
                long long right=(n-i);
                cnt+=(left*right);
            }
        }
        return cnt;
    }
};