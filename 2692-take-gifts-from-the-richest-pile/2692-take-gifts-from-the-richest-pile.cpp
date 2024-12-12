class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;
        int n=gifts.size();
        for(int i=0;i<n;i++){
              pq.push(gifts[i]);
        }
        long long sum=0;
        while(k--){
            int temp=pq.top();
            temp=sqrt(temp);
            pq.pop();
            pq.push(temp);

        }
        while(!pq.empty()){
            sum+=pq.top();
            pq.pop();

        }
        return sum;
    }
};