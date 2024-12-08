class MyCalendar {
public:
    set<pair<int,int>> bookings;
    MyCalendar() {
        
    }
    
    bool book(int startTime, int endTime) {
     for(const auto& book:bookings){
        if(max(book.first,startTime)<min(book.second,endTime))
        return false;
     }
     bookings.insert({startTime,endTime});
     return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */