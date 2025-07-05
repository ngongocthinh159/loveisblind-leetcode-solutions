#define ll long long
struct SegTree {
    struct Data {
        int cnt;
        ll sum;
    };
    vector<Data> node;
    int n;
    vector<int> y;
    SegTree(int sz, vector<int> &y) {
        n = sz;
        node.resize(4*n);
        this->y = y;
    }
    void update(int idx, int s, int e, int l, int r, int delta) {
        if (s > r || l > e || s > e || l > r) return;
        if (l <= s && e <= r) {
            node[idx].cnt += delta;
        } else {
            int m = (s + e)/2;
            update(2*idx, s, m, l, r, delta);
            update(2*idx + 1, m + 1, e, l, r, delta);
        }
        // merge
        if (node[idx].cnt > 0)
            node[idx].sum = y[e + 1] - y[s];
        else {
            if (s == e)
                node[idx].sum = 0;
            else
                node[idx].sum = node[2*idx].sum + node[2*idx + 1].sum;
        }
    }
    ll coveredSum() {
        return node[1].sum;
    }
};
struct Event {
    int x, y1, y2, delta;
};
class Solution {
public:
    const int MOD = 1e9 + 7;
    int rectangleArea(vector<vector<int>>& rectangles) {
        int n = rectangles.size();
        vector<Event> events;
        vector<int> y(2*n);
        int top = 0;
        for (auto &r : rectangles) {
            auto [x1, y1, x2, y2] = tie(r[0], r[1], r[2], r[3]);
            y[top++] = y1;
            y[top++] = y2;
            events.push_back(Event{x1, y1, y2, 1});
            events.push_back(Event{x2, y1, y2, -1});
        }
        sort(y.begin(), y.end());
        y.erase(unique(y.begin(), y.end()), y.end());
        unordered_map<int,int> yToIdx;
        for (int i = 0; i < (int) y.size(); i++) yToIdx[y[i]] = i;
        sort(events.begin(), events.end(), [](auto &e1, auto &e2) {
            return e1.x < e2.x;
        });
        int segments = 2*n - 1;
        SegTree tree(segments, y);
        int prev_x = 0;
        long long ans = 0;
        for (int i = 0; i < (int) events.size(); i++) {
            ans += 1LL * (events[i].x - prev_x) * tree.coveredSum() % MOD;
            if (ans >= MOD)
                ans -= MOD;
            prev_x = events[i].x;
            tree.update(1, 0, segments - 1, yToIdx[events[i].y1], yToIdx[events[i].y2] - 1, events[i].delta);
        }
        return ans;
    }
};