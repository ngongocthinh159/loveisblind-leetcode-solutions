#define ll long long
#define N 10005
#define M 20500
const int MOD = 1e9 + 7;
int spf[N];
ll fact[M], inv[M];
ll expo(ll a, ll b) {
    ll res = 1;
    ll cur = a;
    while (b) {
        if (b & 1) res = res * cur % MOD;
        cur = cur * cur % MOD;
        b >>= 1;
    }
    return res;
}
auto init = []{
    for (int i = 1; i < N; i++) spf[i] = i;
    for (int i = 2; i * i < N; i++) if (spf[i] == i)
        for (int j = i * i; j < N; j += i) spf[j] = min(spf[j], i);
    fact[0] = 1;
    for (int i = 1; i < M; i++) fact[i] = fact[i - 1] * i % MOD;
    inv[M - 1] = expo(fact[M - 1], MOD - 2);
    for (int i = M - 2; i >= 0; i--) inv[i] = inv[i + 1] * (i + 1) % MOD;
    return 0;
}();
ll nCk(int n, int k) {
    if (k > n) return 0;
    return fact[n] * inv[n - k] % MOD * inv[k] % MOD;
}
class Solution {
public:
    vector<pair<int,int>> buf;
    int top = 0;
    void factorize(int x) {
        top = 0;
        while (x != 1) {
            int fact = spf[x], cnt = 0;
            while (x % fact == 0) { x /= fact, cnt++; }
            buf[top++] = {fact, cnt};
        }
    }
    vector<int> waysToFillArray(vector<vector<int>>& queries) {
        buf.resize(15);
        vector<int> ans(queries.size());
        for (int j = 0; j < queries.size(); j++) {
            int n = queries[j][0];
            int k = queries[j][1];
            factorize(k);
            ll res = 1;
            for (int i = 0; i < top; i++) {
                res = res * nCk(buf[i].second + n - 1, n - 1) % MOD;
            }
            ans[j] = res;
        }
        return ans;
    }
};