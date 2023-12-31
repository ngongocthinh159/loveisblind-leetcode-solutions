class Solution {
public:
    /*
        https://www.youtube.com/watch?v=_334cqdmzns
        sweep line algorithm
    */
    struct Event {
        int time;
        int type; // 0: insert interval, 1: remove interval, 2: query
        int len;
        int idx;
    };
    struct comparator {
        bool operator() (const Event &e1, const Event &e2) const {
            if (e1.time < e2.time) return true;
            if (e1.time == e2.time && 
                ((e1.type == 0 && e2.type == 2) || (e1.type == 1 && e2.type == 2))) return true;
            return false;
        }
    };
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        vector<Event> v;
        for (int i = 0; i < intervals.size(); i++) {
            Event event1;
            event1.time = intervals[i][0];
            event1.type = 0;
            event1.len = intervals[i][1] - intervals[i][0] + 1;

            Event event2;
            event2.time = intervals[i][1] + 1;
            event2.type = 1;
            event2.len = intervals[i][1] - intervals[i][0] + 1;

            v.push_back(event1);
            v.push_back(event2);
        }
        for (int i = 0; i < queries.size(); i++) {
            Event event;
            event.time = queries[i];
            event.type = 2;
            event.idx = i;
            v.push_back(event);
        }
        sort(v.begin(), v.end(), comparator());
        vector<int> res(queries.size());
        map<int,int> mp;
        for (int i = 0; i < v.size(); i++) {
            Event e = v[i];
            if (e.type == 0) {
                mp[e.len]++;
            } else if (e.type == 1) {
                if (!(--mp[e.len])) mp.erase(e.len);
            } else if (e.type == 2) {
                if (!mp.size()) res[e.idx] = -1;
                else res[e.idx] = (*mp.begin()).first;
            }
        }
        return res;
    }
};