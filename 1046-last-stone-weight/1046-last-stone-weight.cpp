class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        int n=stones.size();
        for(int i=0;i<n;i++)
        {
            pq.push(stones[i]);
        }

        while(pq.size()>1)
        {
            int top=pq.top();
            pq.pop();
            int secTop=pq.top();
            pq.pop();
            if(top!=secTop) pq.push(top-secTop);
        }
        if(pq.size()==0) return 0;
        return  pq.top();
    }
};