#define ll long long
vector<ll> fact(1001);
vector<ll> ifact(1001);
const int MOD  = 1e9 + 7;
bool ok = false;
long long s[1001][1001], mod = 1e9 + 7;
auto init = [] {
    s[0][0] = 1;
    for (int i = 1; i <= 1000; i++)
        for (int j = 1; j <= i; j++)
            s[i][j] = (s[i - 1][j - 1] + s[i - 1][j] * j) % mod;
    return 0;
}();
ll expo(ll a, ll b, ll mod) {
    if (b == 1) return a;
    if (b == 0) return 1;

    ll tmp = expo(a, b/2, mod);
    if (b & 1) return ((tmp * tmp) % MOD) * a % MOD;
    return tmp * tmp % MOD;
}
void precal() {
    fact[0] = 1;
    for (int i = 1; i <= 1000; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }
    ifact[1000] = expo(fact[1000], MOD - 2, MOD);
    for (int i = 1000 - 1; i >= 0; i--) {
        ifact[i] = ifact[i + 1] * (i + 1) % MOD;
    }
}
ll comb(int n, int r) {
    return (fact[n] * ifact[r] % MOD) * ifact[n - r] % MOD;
}
class Solution {
public:
    ll f(int a, int b, int y, int x, vector<ll> _yPow) {
        ll res = comb(x, b);
        res = (res * s[a][b]) % MOD;
        res = (res * fact[b]) % MOD;
        res = (res * _yPow[b]) % MOD;
        return res;
    }
    int numberOfWays(int n, int x, int y) {
        if (!ok) {
            ok = true;
            precal();
        }
        vector<ll> _yPow(x + 1);
        _yPow[0] = 1;
        for (int i = 1; i <= x; i++) {
            _yPow[i] = _yPow[i - 1] * y % MOD;
        }
        ll res = 0;
        for (int i = 1; i <= x; i++) {
            if (n >= i) {
                res = (res + f(n, i, y, x, _yPow)) % MOD;
            }
        }
        return res;
    }
};