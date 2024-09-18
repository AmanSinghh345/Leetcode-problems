class Solution {
    public int fillCups(int[] amount) {
        
           PriorityQueue<Integer> pq=new PriorityQueue<Integer>((a,b) ->(b-a));
           for(int v:amount){
            pq.offer(v);
           }
           int count=0;
           while(!pq.isEmpty()){
            int first=pq.poll();
            int second=pq.poll();
            if(first<=0 && second<=0) break;
            first--;
            second--;
            pq.offer(first);
            pq.offer(second);
            count++;
           }
            



         return count;
    }
}