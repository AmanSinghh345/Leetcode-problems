class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        int row=score.size();
        int col=score[0].size();
        vector<int> arr;
        for(int i=0;i<row;i++){
            arr.push_back(score[i][k]);
        }
        sort(arr.rbegin(),arr.rend());
        vector<vector<int>> ans(row);
        for(int i=0;i<arr.size();i++){
            for(int j=0;j<row;j++){
            if(score[j][k]==arr[i]){
                ans[i]=score[j];
                break;
            }
        }
        }
        return ans;
        
    }
};