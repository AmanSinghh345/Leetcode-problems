class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n=nums.size();
        long long ans=0;
        priority_queue<pair<int,int>,vector<pair<int,int>> , greater<pair<int,int>>> pq;
        for(int i=0;i<n;i++) {
            pq.push(make_pair(nums[i],i ));
        }
        unordered_set<int> st;
        while(!pq.empty()){
            pair<int,int> temp=pq.top();
            pq.pop();
            int val=temp.first;
            int index=temp.second;
            if(st.count(index)) continue;
            ans+=val;
            st.insert(index);
            st.insert(index+1);
            
            st.insert(index-1);
        }
        return ans;
    }
};