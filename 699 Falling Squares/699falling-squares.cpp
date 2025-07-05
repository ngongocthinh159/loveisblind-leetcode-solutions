const int IINF = 1e9;
struct SegTree {
    struct Data {
        int mx;
    };
    vector<Data> node;
    vector<int> lazy;
    int n;
    SegTree(int sz) {
        n = sz;
        node.resize(4*n);
        lazy.resize(4*n);
    }
    void apply(int idx, int s, int e, int setVal) {
        node[idx].mx = setVal;
        lazy[idx] = max(lazy[idx], setVal);
    }
    void push_down(int idx, int s, int e) {
        if (lazy[idx]) {
            int m = (s + e)/2;
            apply(2*idx, s, m, lazy[idx]);
            apply(2*idx + 1, m + 1, e, lazy[idx]);
            lazy[idx] = 0;
        }
    }
    void update(int idx, int s, int e, int l, int r, int setVal) {
        if (s > r || l > e || s > e || l > r) return;
        if (l <= s && e <= r) {
            apply(idx, s, e, setVal);
            return;
        };
        push_down(idx, s, e);
        int m = (s + e)/2;
        update(2*idx, s, m, l, r, setVal);
        update(2*idx + 1, m + 1, e, l, r, setVal);
        node[idx].mx = max(node[2*idx].mx, node[2*idx + 1].mx);
    }
    int query(int idx, int s, int e, int l, int r) {
        if (s > r || l > e || s > e || l > r) return -IINF;
        if (l <= s && e <= r)
            return node[idx].mx;
        push_down(idx, s, e);
        int m = (s + e)/2;
        int lans = query(2*idx, s, m, l, r);
        int rans = query(2*idx + 1, m + 1, e, l, r);
        return max(lans, rans);
    }
};
class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        int n = positions.size();
        vector<int> x(2*n);
        int top = 0;
        for (int i = 0; i < n; i++) {
            x[top++] = positions[i][0];
            x[top++] = positions[i][0] + positions[i][1];
        }
        sort(x.begin(), x.end(), [](int x1, int x2) {
            return x1 < x2;
        });
        x.erase(unique(x.begin(), x.end()), x.end());
        unordered_map<int,int> xToIdx;
        for (int i = 0; i < (int) x.size(); i++) xToIdx[x[i]] = i;
        int segments = (int) x.size() - 1;
        SegTree tree(segments);
        vector<int> ans(n);
        int cur_max = 0;
        for (int i = 0; i < n; i++) {
            int l = xToIdx[positions[i][0]];
            int r = xToIdx[positions[i][0] + positions[i][1]] - 1;
            int mx = tree.query(1, 0, segments - 1, l, r);
            // cout << mx << '\n';
            tree.update(1, 0, segments - 1, l, r, mx + positions[i][1]);
            cur_max = max(cur_max, mx + positions[i][1]);
            ans[i] = cur_max;
        }
        return ans;
    }
};