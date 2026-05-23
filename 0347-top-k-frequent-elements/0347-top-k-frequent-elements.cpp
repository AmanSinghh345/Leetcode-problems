class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int,int> freq;
        for(int x : nums){
            freq[x]++;
        }

        vector<vector<int>> bucket(nums.size()+1);

        for(auto [num,cnt]: freq){
            bucket[cnt].push_back(num);
        }

        vector<int> ans;
        for(int i=bucket.size()-1;i>=0;i--){
            for(int j=0;j<bucket[i].size() && ans.size()<k;j++){
                ans.push_back(bucket[i][j]);
            
            }
                if(ans.size()==k) break;
        }
        return ans;
    }
};