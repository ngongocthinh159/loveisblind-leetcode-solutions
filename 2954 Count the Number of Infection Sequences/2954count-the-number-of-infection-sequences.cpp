#define MAXN 100005
#define ll long long
const int MOD = 1e9 + 7;
ll fact[MAXN], inv[MAXN], _2pow[MAXN];
ll expo(ll a, ll p) {
    ll res = 1;
    ll cur = a;
    while (p) {
        if (p&1)
            res = res * cur % MOD;
        cur = cur * cur % MOD;
        p >>= 1;
    }
    return res;
}
auto init = []{
    fact[0] = 1;
    for (int i = 1; i < MAXN; i++) fact[i] = fact[i - 1] * i % MOD;
    inv[MAXN - 1] = expo(fact[MAXN - 1], MOD - 2);
    for (int i = MAXN - 2; i >= 0; i--) inv[i] = inv[i + 1] * (i + 1) % MOD;
    _2pow[0] = 1;
    for (int i = 1; i < MAXN; i++) _2pow[i] = _2pow[i - 1] * 2 % MOD;
    return 0;
}();
ll nCk(int n, int k) {
    return fact[n] * inv[k] % MOD * inv[n - k] % MOD;
}
class Solution {
public:
    int numberOfSequence(int n, vector<int>& sick) {
        vector<int> v(n);
        for (auto x : sick) v[x] = 1;
        int i = 0, tot = n - sick.size();
        bool foundl = false;
        ll ans = 1;
        while (i < n) {
            if (v[i] == 1) {
                foundl = true;
                i++;
                continue;
            }
            int start = i, end = i;
            while (i < n && v[i] == 0) {
                end = i;
                i++;
            }
            bool foundr = false;
            if (end + 1 < n) foundr = true;
            if (foundl && foundr) {
                ans = ans * _2pow[end - start] % MOD;
            }
            ans = ans * nCk(tot, end - start + 1) % MOD;
            tot -= (end - start + 1);
        }
        return ans;
    }
};