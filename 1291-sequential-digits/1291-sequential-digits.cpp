class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        queue<int> q;
        for(int i=1;i<=9;i++) q.push(i);    

        while(!q.empty()){
            int x=q.front();
            q.pop();

            if(x>=low && x<=high) ans.push_back(x);

            int ld=x%10;
            if(ld<9){
                int val=x*10+ld+1;
                if( val<=high) q.push(val);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};