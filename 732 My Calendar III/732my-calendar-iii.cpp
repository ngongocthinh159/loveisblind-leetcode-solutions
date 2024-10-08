class MyCalendarThree {
public:
    map<int,int> cnt;
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        cnt[start]++;
        cnt[end]--;
        int mx = INT_MIN;
        int bookings = 0;
        for (auto &[time, _book_cnt] : cnt) {
            bookings += _book_cnt;
            mx = max(mx, bookings);
        }
        return mx;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */