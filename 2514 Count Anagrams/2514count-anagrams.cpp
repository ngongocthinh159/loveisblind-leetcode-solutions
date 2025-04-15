#define ll long long
#define N 100005
ll per[N], inv_per[N];
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
    per[0] = 1;
    for (int i = 1; i < N; i++) per[i] = per[i - 1] * i % MOD;
    inv_per[N - 1] = expo(per[N - 1], MOD - 2);
    for (int i = N - 2; i >= 0; i--) inv_per[i] = inv_per[i + 1] * (i + 1) % MOD;
    return 0;
}();
class Solution {
public:
    int countAnagrams(string s) {
        ll res = 1;
        int i = 0, n = s.size();
        while (i < n) {
            vector<int> freq(26, 0);
            while (i < n && s[i] == ' ') i++;
            int start = i, end = -1;
            while (i < n && s[i] != ' ') freq[s[i] - 'a']++, end = i, i++;
            if (end != -1) {
                ll cur = per[end - start + 1];
                for (int i = 0; i < 26; i++) cur = cur * inv_per[freq[i]] % MOD;
                res = res * cur % MOD;
            }
        }
        return res;
    }
};