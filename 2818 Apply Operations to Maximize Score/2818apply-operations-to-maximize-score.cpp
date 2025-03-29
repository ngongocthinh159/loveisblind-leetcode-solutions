#define MAXN 100005
#define ll long long
const int MOD = 1e9 + 7;
int spf[MAXN], score[MAXN];
auto init = []{
    for (int i = 0; i < MAXN; i++) spf[i] = i;
    for (int i = 2; i * i < MAXN; i++) if (spf[i] == i)
        for (int j = i * i; j < MAXN; j += i) spf[j] = min(spf[j], i);
    for (int i = 2; i < MAXN; i++) {
        int dif = 0, x = i;
        while (x != 1) {
            int fact = spf[x];
            while (x % fact == 0) x /= fact;
            dif++;
        }
        score[i] = dif;
    }
    return 0;
}();
ll expo(ll a, ll b) {
    ll res = 1;
    ll cur = a;
    while (b) {
        if (b&1)
            res = res * cur % MOD;
        cur = cur * cur % MOD;
        b >>= 1;
    }
    return res;
}
class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> L(n), R(n), st, order(n);
        for (int i = 0; i < n; i++) {
            while (st.size() && score[nums[st.back()]] < score[nums[i]]) st.pop_back();
            L[i] = st.size() ? st.back() : -1;
            st.push_back(i);
        }
        st.clear();
        for (int i = n - 1; i >= 0; i--) {
            while (st.size() && score[nums[st.back()]] <= score[nums[i]]) st.pop_back();
            R[i] = st.size() ? st.back() : n;
            st.push_back(i);
        }
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int i, int j) {
            return nums[i] > nums[j];
        });
        ll res = 1;
        for (int i = 0; i < n && k; i++) {
            ll can = 1LL * (order[i] - L[order[i]]) * (R[order[i]] - order[i]);
            ll take = min(can, 1LL*k);
            res = res * expo(nums[order[i]], take) % MOD;

            k -= take;
        }
        return res;
    }
};