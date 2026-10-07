class StockSpanner {
    stack<int> st;
    vector<int> arr;
    int idx=0;
public:
    StockSpanner() {

    }
    
    int next(int price) {
        arr.push_back(price);
        while(!st.empty() && arr[st.top()]<=price) st.pop();
       int ans;
       if(!st.empty()) ans=idx-st.top();
       else ans=idx+1;
       st.push(idx);
       idx++;
       return ans;
        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */