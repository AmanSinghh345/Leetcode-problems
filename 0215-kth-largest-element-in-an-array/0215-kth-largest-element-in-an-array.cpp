#define all(x) x.begin(),x.end()
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>> pq;
        int n=nums.size();
        for(auto it : nums)
        {
            pq.push(it);
        }
        for(int i=1;i<k;i++)
        pq.pop();
        return pq.top();
    }
};