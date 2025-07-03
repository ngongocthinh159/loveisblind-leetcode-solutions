#define MAX 100005
#define ll long long
ll fact2[10], inv2[10], fact5[10], inv5[10];
unordered_map<int,int> dp[2][MAX];

int M[2][5];
ll expo(ll a, ll b, ll mod) {
    ll res = 1;
    ll cur = a;
    while (b) {
        if (b&1)
            res = res * cur % mod;
        cur = cur * cur % mod;
        b >>= 1;
    }
    return res;
}
auto init = []{
    fact2[0] = fact2[1] = 1;
    inv2[0] = inv2[1] = 1;

    fact5[0] = 1;
    for (int i = 1; i < 5; i++) fact5[i] = fact5[i - 1] * i % 5;
    inv5[4] = expo(fact5[4], 5 - 2, 5);
    for (int i = 3; i >= 0; i--) inv5[i] = inv5[i + 1] * (i + 1) % 5;

    for (int i = 0; i <= 9; i++) {
        M[i%2][i%5] = i;
    }
    return 0;
}();
ll nCk2(int n, int k) {
    if (k > n) return 0;
    return fact2[n] * inv2[k] * inv2[n - k] % 2;
}
ll nCk5(int n, int k) {
    if (k > n) return 0;
    return fact5[n] * inv5[k] * inv5[n - k] % 5;
}
class Solution {
public:
    ll nCkLucas(int n, int k, int mod) {
        if (k > n) return 0;
        if (dp[mod == 2 ? 0 : 1][n].count(k)) return dp[mod == 2 ? 0 : 1][n][k];
        int N = n, K = k;
        ll res = 1;
        while (K) {
            int nc = N % mod;
            int kc = K % mod;
            if (mod == 2)
                res = res * nCk2(nc, kc) % mod;
            else
                res = res * nCk5(nc, kc) % mod;
            N /= mod;
            K /= mod;
        }
        return dp[mod == 2 ? 0 : 1][n][k] = res;
    }
    ll nCk10(int n, int k) {
        int f = nCkLucas(n, k, 2);
        int s = nCkLucas(n, k, 5);
        return M[f][s];
    }
    int cal(int i, int len, string &s) {
        int res = 0;
        for (int j = i, k = 0; j <= i + len; j++, k++) {
            res += nCk10(len, k) * (s[j] - '0') % 10;
            if (res >= 10) res -= 10;
        }
        return res;
    }
    bool hasSameDigits(string s) {
        int n = s.size();
        int len = n - 2;
        return cal(0, len, s) == cal(1, len, s);
    }
};