#define ll long long
#define N 100005
ll fact[N], inv[N];
const int MOD = 1e9 + 7;
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
    return fact[n] * inv[k] % MOD * inv[n - k] % MOD;
}
class Solution {
public:
    int countGoodArrays(int n, int m, int k) {
        return 1LL * nCk(n - 1, k) * expo(m - 1, n - 1 - k) % MOD * m % MOD;
    }
};