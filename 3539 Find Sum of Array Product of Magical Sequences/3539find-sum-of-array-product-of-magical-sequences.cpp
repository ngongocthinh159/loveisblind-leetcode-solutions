#define ll long long
#define K 35
const int MOD = 1e9 + 7;
ll fact[K], inv[K];
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
    for (int i = 1; i < K; i++) fact[i] = fact[i - 1] * i % MOD;
    inv[K - 1] = expo(fact[K - 1], MOD - 2);
    for (int i = K - 2; i >= 0; i--) inv[i] = inv[i + 1] * (i + 1) % MOD;
    return 0;
}();
int nCk(int n, int k) {
    if (k > n) return 0;
    return fact[n] * inv[k] % MOD * inv[n - k] % MOD;
}
class Solution {
public:
    vector<vector<vector<vector<int>>>> dp;
    int dfs(int i, int m, int mask, int set_bits, int k, vector<int> &nums) {
        if (m == 0) {
            return __builtin_popcount(mask) + set_bits == k;
        }
        if (set_bits > k) return 0;
        if (i == nums.size()) return 0;
        if (dp[i][m][set_bits][mask] != -1) return dp[i][m][set_bits][mask];

        ll res = dfs(i + 1, m, mask >> 1, set_bits + (mask&1), k, nums);
        for (int j = 1; j <= m; j++) {
            int mul = 1LL * nCk(m, j) * expo(nums[i], j) % MOD;
            int nmask = (mask + j) >> 1;
            int nset_bits = set_bits + ((mask + j) & 1);
            res = (res + 1LL * dfs(i + 1, m - j, nmask, nset_bits, k, nums) * mul % MOD);
            if (res >= MOD) res -= MOD;
        }
        return dp[i][m][set_bits][mask] = res;
    }
    int magicalSum(int m, int k, vector<int>& nums) {
        int n = nums.size();
        dp = vector<vector<vector<vector<int>>>>(n,
            vector<vector<vector<int>>>(m + 1,
                vector<vector<int>>(k + 1,
                    vector<int>(1 << 6, -1))));
        return dfs(0, m, 0, 0, k, nums);
    }
};