class Solution {
public:
    string getPermutation(int n, int k) {
        long long fact=1;
        for(int i=1;i<n;i++) fact*=i;
        vector<int> numbers;
        for(int i=1;i<=n;i++) numbers.push_back(i);
        string ans;
        k--;
        while(1){
            int ind=k/fact;
            ans+=numbers[ind]+'0';
            numbers.erase(numbers.begin()+ind);
            if(numbers.size()==0) break;
            k=k%fact;
            fact/=numbers.size();
        }
        return ans;
    }
};