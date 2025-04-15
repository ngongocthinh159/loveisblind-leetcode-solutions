struct FenwickTree {
    vector<int> bit;
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> const &a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        if (l > r) return 0;
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

class Solution {
public:
    const int MOD = 1e9 + 7;
    int createSortedArray(vector<int>& instructions) {
        int n = instructions.size();
        vector<int> mapping = instructions, arr = instructions;
        sort(mapping.begin(), mapping.end());
        mapping.erase(unique(mapping.begin(), mapping.end()), mapping.end());
        for (int i = 0; i < n; i++)
            arr[i] = lower_bound(mapping.begin(), mapping.end(), arr[i]) - mapping.begin();
        int m = mapping.size();
        FenwickTree tree(m);
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            ans += min(tree.sum(0, arr[i] - 1), tree.sum(arr[i] + 1, m - 1));
            if (ans >= MOD) ans -= MOD;
            tree.add(arr[i], 1);
        }
        return ans;
    }
};