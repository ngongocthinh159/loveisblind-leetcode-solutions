#define ll long long
class Solution {
public:
    const int MOD = 1e9 + 7;
    ll expo(ll a, ll b) {
        ll res = 1;
        ll cur = a;
        while (b) {
            if (b&1) res = res * cur % MOD;
            cur = cur * cur % MOD;
            b >>= 1;
        }
        return res;
    }
    int countGoodNumbers(long long n) {
        return expo(5, (n + 1)/2) * expo(4, n/2) % MOD;
    }
};