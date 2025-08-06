struct SegTree {
    vector<int> segtree;
    int n;
    SegTree(vector<int> &arr) {
        n = arr.size();
        segtree.resize(4*n);
        build(1, 0, n - 1, arr);
    }
    void build(int idx, int s, int e, vector<int> &arr) {
        if (s == e) {
            segtree[idx] = arr[s];
            return;
        }
        int m = (s + e)/2;
        build(2*idx, s, m, arr);
        build(2*idx + 1, m + 1, e, arr);
        segtree[idx] = merge(segtree[2*idx], segtree[2*idx + 1]);
    }
    int merge(int l, int r) {
        return max(l, r);
    }
    void update(int idx, int s, int e, int pos, int val) {
        if (s == e) {
            segtree[idx] = val;
            return;
        }
        int m = (s + e)/2;
        if (pos <= m)
            update(2*idx, s, m, pos, val);
        else
            update(2*idx + 1, m + 1, e, pos, val);
        segtree[idx] = merge(segtree[2*idx], segtree[2*idx + 1]);
    }
    int query(int idx, int s, int e, int val) {
        if (segtree[idx] < val) return -1;
        if (s == e) return s;
        int m = (s + e)/2;
        if (segtree[2*idx] >= val)
            return query(2*idx, s, m, val);
        else
            return query(2*idx + 1, m + 1, e, val);
    }
};

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        int placed = 0;
        SegTree tree(baskets);
        for (int i = 0; i < n; i++) {
            int idx = tree.query(1, 0, n - 1, fruits[i]);
            if (idx != -1) {
                placed++;
                baskets[idx] = 0;
                tree.update(1, 0, n - 1, idx, baskets[idx]);
            }
        }
        return n - placed;
    }
};