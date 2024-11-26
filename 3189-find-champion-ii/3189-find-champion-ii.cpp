class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> arr(n,0);
        for(auto & edge:edges){
            int x=edge[0];
            int y=edge[1];
            arr[y]++;
        }
        int ans=-1;
        for(int i=0;i<n;i++){
            if(ans!=-1 && arr[i]==0){
                return -1;
            }
            if(ans==-1 && arr[i]==0){
                ans=i;
            }
        }
        return ans;
    }
};