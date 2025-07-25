class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        sort(changed.begin(),changed.end());
        int n=changed.size();
        vector<int> ans;
        if(n&1) return ans;
        int l=n-2,r=n-1;
        while(r>0 and l>=0){
            if( changed[l]*2==changed[r]){
                if(l==r){
                    if(l>=1) l--;
                }
                ans.push_back(changed[l]);
                changed[l]=-1;
                changed[r]=-1;
                if(l>=1)
                l--;
            }
            else{
                while(l>=0 and changed[l]*2!=changed[r]){
                    l--;
                }
            }
            while(r>0 and changed[r]==-1){
                r--;
            }
        }
        for(int i=0;i<n;i++){
            if(changed[i]!=-1){
                vector<int> temp;
                return temp;
            }
        }
        return ans;
        }
};