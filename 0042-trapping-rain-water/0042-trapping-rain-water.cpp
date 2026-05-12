class Solution {
public:
    int trap(vector<int>& height) {
        
        int n=height.size();
        int maxi=INT_MIN;
        vector<int> maxiR(n),maxiL(n);
        maxiR[n-1]=-1;
        maxi=height[n-1];
        for(int i=n-2;i>=0;i--){
            if(maxi>height[i]){
                maxiR[i]=maxi;
            }
            else{
                maxiR[i]=-1;
                maxi=height[i];
            }
        }
        maxiL[0]=-1;
        maxi=height[0];
        for(int i=1;i<n;i++){
            if(maxi>height[i]){
                maxiL[i]=maxi;
            }
            else{
                maxiL[i]=-1;
                maxi=height[i];
            }
        }
        int contribution=0;
        for(int i=0;i<n;i++){
            if(maxiL[i]==-1 || maxiR[i]==-1) contribution+=0;
            else{
                int take=min(maxiR[i],maxiL[i]);
                int contribute=take-height[i];
                contribution+=contribute;
            }
        }
        return contribution;
    }
};