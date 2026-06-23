class Solution {
public:
    int minLights(vector<int>& lights) {
        int n=lights.size();
        vector<int> diff(n,0);
        for(int i=0;i<n;i++){
            if(lights[i]!=0){
                int left=max(0,i-lights[i]);
                int right=min(n-1,i+lights[i]);
                if(left<0) diff[0]+=1;
                else diff[left]+=1;
                if(right+1<n)
                diff[right+1]-=1;
            }
        }
        for(int i=1;i<n;i++){
            diff[i]+=diff[i-1];
        }
        int cnt=0;
        int zero=0;
        for(int i=0;i<n;i++){
            if(diff[i]!=0 && zero>0){
                cnt++;
                zero=0;
            }
            else if(diff[i]==0){
                zero++;
                if(zero==3) {
                    cnt++;
                    zero=0;
                }
            }
        }
        
        if(zero>0) cnt++;
        return cnt;
    }
};