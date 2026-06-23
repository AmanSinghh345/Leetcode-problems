class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int n=heights.size();
        vector<int> freq(101,0);
        for(int i=0;i<n;i++){
            freq[heights[i]]++;
        }
        int cnt=0;
        int currHeight=1;
        for(int i=0;i<n;i++){
            while(freq[currHeight]==0){
                currHeight++;
            }
            if(heights[i]!=currHeight) cnt++;
            freq[currHeight]--;
        }
        return cnt;

    }
};