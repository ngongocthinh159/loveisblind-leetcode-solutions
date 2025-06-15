struct SegTree {
    struct Data {
        int freq[5]{};
        int prod;
    };
    vector<Data> segtree;
    Data defaultValue;
    int n, k;
    SegTree(vector<int> &nums, int _k) {
        n = nums.size();
        k = _k;
        segtree.resize(4*n);

        defaultValue.prod = 1;
  
        build(1, 0, n - 1, nums);
    }
    void merge(Data &root, Data &l, Data &r) {
        for (int i = 0; i < k; i++) root.freq[i] = 0;
        for (int i = 0; i < k; i++) root.freq[i] += l.freq[i];
        for (int i = 0; i < k; i++) root.freq[i * l.prod % k] += r.freq[i];
        root.prod = 1LL * l.prod * r.prod % k;
    }
    void build(int idx, int s, int e, vector<int>&nums) {
        if (s == e) {
            int x = nums[s] % k;
            segtree[idx].freq[x]++;
            segtree[idx].prod = x;
            return;
        }
        int m = (s + e)/2;
        build(2*idx, s, m, nums);
        build(2*idx + 1, m + 1, e, nums);
        merge(segtree[idx], segtree[2*idx], segtree[2*idx + 1]);
    }
    void update(int idx, int s, int e, int pos, int val) {
        if (s == e) {
            for (int i = 0; i < k; i++) segtree[idx].freq[i] = 0;
            int x = val % k;
            segtree[idx].freq[x]++;
            segtree[idx].prod = x;
            return;
        }
        int m = (s + e)/2;
        if (pos <= m)
            update(2*idx, s, m, pos, val);
        else
            update(2*idx + 1, m + 1, e, pos, val);
        merge(segtree[idx], segtree[2*idx], segtree[2*idx + 1]);
    }
    Data query(int idx, int s, int e, int l, int r) {
        if (s > r || l > e || s > e || l > r) return defaultValue;
        if (l <= s && e <= r)
            return segtree[idx];
        int m = (s + e)/2;
        Data lans = query(2*idx, s, m, l, r);
        Data rans = query(2*idx + 1, m + 1, e, l, r);
        Data res;
        merge(res, lans, rans);
        return res;
    }
};
class Solution {
public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        int n = nums.size(), m = queries.size();
        SegTree tree(nums, k);
        vector<int> ans(m);
        for (int i = 0; i < m; i++) {
            tree.update(1, 0, n - 1, queries[i][0], queries[i][1]);
            ans[i] = tree.query(1, 0, n - 1, queries[i][2], n - 1).freq[queries[i][3]];
        }
        return ans;
    }
};