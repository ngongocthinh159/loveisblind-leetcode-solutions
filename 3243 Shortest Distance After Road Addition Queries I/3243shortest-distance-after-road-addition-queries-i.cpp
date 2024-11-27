struct Data {
    int val;
};
enum LazyType { NONE, MINIMIZE };
struct Lazy {
    LazyType type = NONE;
    int val = 1e8;
};
struct SegTree {
    vector<Data> segtree;
    vector<Lazy> lazy;
    int n;
    vector<int> arr;
    SegTree(int n, vector<int> &arr) {
        this->n = n;
        this->arr = arr;
        segtree.resize(4*n);
        lazy.resize(4*n);
        build(1, 0, n - 1);
    }
    void build(int idx, int s, int e) {
        if (s == e) {
            segtree[idx] = Data(arr[s]);
            return;
        };
        int m = (s + e)/2;
        build(2*idx, s, m);
        build(2*idx + 1, m + 1, e);
    }
    void apply(int idx, int s, int e, const Lazy &operation) {
        if (operation.type == MINIMIZE) {
            if (s == e) {
                // cout << s << " " << e << " " << segtree[idx].val << " " << operation.val << "\n";
                segtree[idx].val = min(segtree[idx].val, operation.val);
            }
            lazy[idx].val = min(lazy[idx].val, operation.val);
            lazy[idx].type = MINIMIZE;
        }
    }
    void push_down(int idx, int s, int e) {
        int m = (s + e)/2;
        if (lazy[idx].type != NONE)
            apply(2*idx, s, m, Lazy({lazy[idx].type, lazy[idx].val + (e - m)}));
            apply(2*idx + 1, m + 1, e, lazy[idx]);
        lazy[idx] = Lazy();
    }
    void update(int idx, int s, int e, int l, int r, const Lazy& operation) {
        if (s > r || e < l) return;
        if (l <= s && e <= r) {
            apply(idx, s, e, Lazy({operation.type, operation.val + (r - e)}));
            return;
        }
        push_down(idx, s, e);
        int m = (s + e)/2;
        update(2*idx, s, m, l, r, operation);
        update(2*idx + 1, m + 1, e, l, r, operation);
    }
    Data query(int idx, int s, int e, int pos) {
        // cout << s << " " << e << "\n";
        if (s == e) return segtree[idx];
        push_down(idx, s, e);
        int m = (s + e)/2;
        if (pos <= m) return query(2*idx, s, m, pos);
        return query(2*idx + 1, m + 1, e, pos);
    }
    Data idx(int idx) {
        return segtree[idx];
    }
};
class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> dp(n);
        for (int i = 0; i < n; i++) dp[i] = (n - i - 1);
        // while (!(n&(n - 1))) {
        //     dp.push_back(0);
        //     n++;
        // }
        // for (int i = 0; i < n; i++) cout << dp[i] << " ";
        // cout << "\n";
        SegTree tree(n, dp);
        // for (int i = 0; i < n; i++) cout << tree.idx(i + n + 1).val << " ";
        // cout << "\n";
        // for (int i = 0; i < n; i++) cout << tree.query(1, 0, n - 1, i).val << "\n";
        vector<int> ans;
        // vector<vector<int>> que;
        // que.push_back({2,4});
        // tree.update(1, 0, n - 1, 0, 2, Lazy({MINIMIZE, 1}));
        // ans.push_back(tree.query(1, 0, n - 1, 0).val);
        for (auto &q : queries) {
            int u = q[0], v = q[1];
            int old_dist_u = tree.query(1, 0, n - 1, u).val;
            int old_dist_v = tree.query(1, 0, n - 1, v).val;
            // cout << old_dist_u << " " << old_dist_v << "\n";
            if (1 + old_dist_v < old_dist_u) {
                // cout << "here" << "\n";
                // cout << 1 + old_dist_v << "\n";
                tree.update(1, 0, n - 1, 0, u, Lazy({MINIMIZE, 1 + old_dist_v}));
            }
            ans.push_back(tree.query(1, 0, n - 1, 0).val);

            // for (int i = 0; i < n; i++) cout << tree.idx(i + n + 1).val << " ";
            // cout << "\n";
        }

        // 0 0 0 0 0 0 0 
        // - - - - -
        //     - - - - -

        return ans;
    }
};