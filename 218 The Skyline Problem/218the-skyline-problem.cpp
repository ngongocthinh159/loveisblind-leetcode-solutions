struct Event {
    int x, h, type;
};
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        int n = buildings.size();
        vector<Event> events;
        for (int i = 0; i < n; i++) {
            auto [l, r, h] = tie(buildings[i][0], buildings[i][1], buildings[i][2]);
            events.push_back(Event{l, h, 1});
            events.push_back(Event{r, h, -1});
        }
        multiset<int> H;
        sort(events.begin(), events.end(), [](auto &e1, auto &e2) {
            return e1.x < e2.x;
        });
        int m = events.size();
        int prev_h = 0;
        vector<vector<int>> res;
        for (int i = 0; i < m;) {
            int curx = events[i].x, curh = events[i].h;
            while (i < m && events[i].x == curx) {
                if (events[i].type == 1) {
                    H.insert(events[i].h);
                } else {
                    H.erase(H.find(events[i].h));
                }
                i++;
            }
            int mx_h = H.size() == 0 ? 0 : *H.rbegin();
            if (prev_h != mx_h) {
                res.push_back({curx, mx_h});
                prev_h = mx_h;
            }
        }
        return res;
    }
};