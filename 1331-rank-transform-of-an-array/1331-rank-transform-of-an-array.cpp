class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> temp=arr;
        sort(arr.begin(),arr.end());
        arr.erase(unique(arr.begin(),arr.end()),arr.end());
        for(int i=0;i<temp.size();i++){
            int ind=lower_bound(arr.begin(),arr.end(),temp[i])-arr.begin()+1;
            temp[i]=ind;
        }
        return temp;
    }
};