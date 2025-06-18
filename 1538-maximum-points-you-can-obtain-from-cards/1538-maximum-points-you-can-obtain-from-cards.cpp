class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
            int n=cardPoints.size();
            int leftSum=0;
            for(int i=0;i<k;i++) leftSum+=cardPoints[i];
            int maxSum=leftSum,rightSum=0;
            int j=n-1;
            for(int i=k-1;i>=0;i--){
                leftSum-=cardPoints[i];
                rightSum+=cardPoints[j];
                j--;
                maxSum=max(maxSum,leftSum+rightSum);
            }
            return maxSum;
    }
};