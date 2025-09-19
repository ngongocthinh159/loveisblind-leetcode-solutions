#define N 100005
int buf[N], order[N], dp[N], buf2[N];
const int MOD = 1e9 + 7;
struct FenwickTree {
    vector<int> bit;  // binary indexed tree
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
        for (; r >= 0; r = (r & (r + 1)) - 1) {
            ret += bit[r];
            if (ret >= MOD) ret -= MOD;
        }
        return ret;
    }

    int sum(int l, int r) {
        int res = sum(r) - sum(l - 1);
        if (res < 0) res += MOD;
        return res;
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1)) {
            bit[idx] += delta;
            if (bit[idx] >= MOD) bit[idx] -= MOD;
        }
    }

    void reset(int sz) {
        for (int i = 0; i < sz; i++) bit[i] = 0;
    }
};
class Solution {
public:
    int totalBeauty(vector<int>& nums) {
        int n = nums.size();
        int mx = *max_element(nums.begin(), nums.end());
        vector<vector<int>> loc(mx + 1);
        for (int i = 0; i < n; i++) loc[nums[i]].push_back(i);
        FenwickTree tree(n + 10);
        int res = 0;
        for (int i = mx; i >= 1; i--) {
            int top = 0;
            for (int j = i; j <= mx; j += i) {
                for (int k = 0; k < (int) loc[j].size(); k++)
                    buf[top] = order[top] = loc[j][k], top++;
            }
            sort(order, order + top);
            int sz = unique(order, order + top) - order;
            for (int j = 0; j < top; j++) {
                auto idx = lower_bound(order, order + sz, buf[j]) - order + 1;
                buf[j] = idx;
            }
            tree.reset(top + 5);
            int ans = 0, top1 = 0;
            for (int j = i; j <= mx; j += i) {
                int top2 = top1, org = top1;
                for (int k = 0; k < (int) loc[j].size(); k++) {
                    buf2[top2] = tree.sum(0, buf[top2] - 1) + 1;
                    if (buf2[top2] >= MOD) buf2[top2] -= MOD;
                    top2++, top1++;
                }
                top2 = org;
                for (int k = 0; k < (int) loc[j].size(); k++) {
                    tree.add(buf[top2], buf2[top2]);
                    ans += buf2[top2];
                    if (ans >= MOD) ans -= MOD;
                    top2++;
                }
            }
            for (int j = 2 * i; j <= mx; j += i) {
                ans -= dp[j];
                if (ans < 0) ans += MOD;
            }
            dp[i] = ans;

            res += 1LL * dp[i] * i % MOD;
            if (res >= MOD) res -= MOD;
        }
        return res;
    }
};