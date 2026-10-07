class StockSpanner {
    stack<int> st;
    vector<int> arr;
    int idx=0;
public:
    StockSpanner() {

    }
    
    int next(int price) {
        while(!st.empty() && arr[st.top()]<=price) st.pop();
        if(!st.empty()){
            int ans=idx-st.top();
            arr.push_back(price);
            st.push(idx);
            idx++;
            return ans;
        }
        int ans=idx+1;
        arr.push_back(price);
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