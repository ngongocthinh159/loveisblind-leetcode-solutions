#define ll long long
#define N 85
const int MOD = 1e9 + 7;
ll fact[N], inv[N];
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
auto init = []{
    fact[0] = 1;
    for (int i = 1; i < N; i++) fact[i] = fact[i - 1] * i % MOD;
    inv[N - 1] = expo(fact[N - 1], MOD - 2);
    for (int i = N - 2; i >= 0; i--) inv[i] = inv[i + 1] * (i + 1) % MOD;
    return 0;
}();
int nCk(int n, int k) {
    if (k > n) return 0;
    return fact[n] * inv[k] % MOD * inv[n - k] %  MOD;
}
class Solution {
public:
    vector<vector<unordered_map<int,int>>> dp;
    vector<pair<int,int>> v;
    int odd_cnt = 0, even_cnt = 0, n;
    int dfs(int i, int odd, int diff, int chosen) {
        if (i == v.size())
            return odd == odd_cnt && diff == 0;
        if (dp[i][odd].count(diff)) return dp[i][odd][diff];

        int even = chosen - odd;
        int x = v[i].first;
        int freq = v[i].second;
        ll res = 0;
        for (int j = 0; j <= min(freq, odd_cnt - odd); j++) {
            int even_will_used = freq - j;
            if (even + even_will_used <= even_cnt) {
                ll cur = dfs(i + 1, odd + j, diff + (j - even_will_used) * x, chosen + freq);
                cur = cur * nCk(odd_cnt - odd, j) % MOD * nCk(even_cnt - even, even_will_used) % MOD;
                res += cur;
                if (res >= MOD) res -= MOD;
            }
        }
        return dp[i][odd][diff] = res;
    }
    int countBalancedPermutations(string num) {
        // i, odd, diff
        n = num.size();
        even_cnt = (n + 1)/2;
        odd_cnt = n - even_cnt;
        int cnt[10]{};
        for (auto c : num) cnt[c - '0']++;
        for (int i = 0; i <= 9; i++) if (cnt[i]) v.push_back({i, cnt[i]});
        dp.assign(v.size(), 
            vector<unordered_map<int,int>>(odd_cnt + 1,
                unordered_map<int,int>()));
        return dfs(0, 0, 0, 0);
    }
};