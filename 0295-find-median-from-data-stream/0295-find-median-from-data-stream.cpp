class MedianFinder {
    priority_queue<int> lo;
    priority_queue<int,vector<int> , greater <> > hi;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        lo.push(num);

        if(!hi.empty() && lo.top()>hi.top()){
            hi.push(lo.top());
            lo.pop();
        }
        if(lo.size()<hi.size()){
            lo.push(hi.top());
            hi.pop();
        }
        if(lo.size()>hi.size()+1){
                hi.push(lo.top());
                lo.pop();
        }
    }
    
    double findMedian() {
       if(lo.size()>hi.size()) return (double)lo.top();
       return (lo.top()+hi.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */