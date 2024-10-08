class MyCalendarTwo {
public:
    map<int,int> cnt;

    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        cnt[start]++;
        cnt[end]--;
        int overlapped = 0;
        for (auto &[time, _cnt] : cnt) {
            overlapped += _cnt;
            if (overlapped >= 3) {
                cnt[start]--;
                cnt[end]++;

                if (cnt[start] == 0) cnt.erase(start);
                if (cnt[end] == 0) cnt.erase(end);
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */