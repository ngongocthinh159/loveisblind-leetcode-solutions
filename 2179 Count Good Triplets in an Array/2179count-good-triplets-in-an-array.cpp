#define ll long long
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
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> mapped(n);
        for (int i = 0; i < n; i++) mapped[nums1[i]] = i;
        for (int i = 0; i < n; i++) nums2[i] = mapped[nums2[i]];
        FenwickTree tree(n);
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            int L = tree.sum(0, nums2[i]);
            int R = n - 1 - nums2[i] - tree.sum(nums2[i], n - 1);
            tree.add(nums2[i], 1);

            ans = ans + 1LL * L * R;
        }
        return ans;
    }
};