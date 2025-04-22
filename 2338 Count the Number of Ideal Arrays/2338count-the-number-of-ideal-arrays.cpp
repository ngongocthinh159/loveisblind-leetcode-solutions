#define ll long long
#define N 20500
int spf[N];
ll fact[N], inv[N];
const int MOD = 1e9 + 7;
pair<int,int> buf[15];
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
auto precom = []{
    for (int i = 1; i < N; i++) spf[i] = i;
    for (int i = 2; i * i < N; i++) if (spf[i] == i)
        for (int j = i * i; j < N; j += i) spf[j] = min(spf[j], i);
    fact[0] = 1;
    for (int i = 1; i < N; i++) fact[i] = fact[i - 1] * i % MOD;
    inv[N - 1] = expo(fact[N - 1], MOD - 2);
    for (int i = N - 2; i >= 0; i--) inv[i] = inv[i + 1] * (i + 1) % MOD;
    return 0;
}();
ll nCk(int n, int k) {
    if (k > n) return 0;
    return fact[n] * inv[k] % MOD * inv[n - k] % MOD;
}
class Solution {
public:
    int top;
    void factorize(int x) {
        top = 0;
        while (x != 1) {
            int fact = spf[x], cnt = 0;
            while ((x / fact) * fact == x) x /= fact, cnt++;
            buf[top++] = {x, cnt};
        }
    }
    int idealArrays(int n, int maxValue) {
        ll ans = 0;
        for (int x = 1; x <= maxValue; x++) {
            ll cur = 1;
            factorize(x);
            for (int j = 0; j < top; j++) {
                int cnt = buf[j].second;
                cur = cur * nCk(n - 1 + cnt, cnt) % MOD;
            }
            ans += cur;
            if (ans >= MOD) ans -= MOD;
        }
        return ans;
    }
};