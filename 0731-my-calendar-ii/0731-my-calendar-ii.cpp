class MyCalendarTwo {
public:
    set<pair<int, int>> bookings;     // Tracks all bookings
    set<pair<int, int>> overlaps;    // Tracks overlaps

    MyCalendarTwo() {}

    bool book(int startTime, int endTime) {
        // Check if this booking causes a triple overlap
        for (const auto& overlap : overlaps) {
            if (max(overlap.first, startTime) < min(overlap.second, endTime)) {
                return false; // Triple overlap detected
            }
        }

        // Update the overlaps set with new overlaps caused by this booking
        for (const auto& book : bookings) {
            if (max(book.first, startTime) < min(book.second, endTime)) {
                overlaps.insert({max(book.first, startTime), min(book.second, endTime)});
            }
        }

        // Add the new booking
        bookings.insert({startTime, endTime});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime, endTime);
 */
