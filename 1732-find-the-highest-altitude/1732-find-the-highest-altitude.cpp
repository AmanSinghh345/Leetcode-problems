class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxi=0;
        int altitude=0;
        for(int x:gain){
            altitude+=x;
            maxi=max(maxi,altitude);
        }
        return maxi;
    }
};