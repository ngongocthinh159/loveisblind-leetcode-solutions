#define ll long long
#define N 2005
ll pref[N], basepow[N];
ll base = 32;
const int MOD = 1e9 + 7;
auto init = []{
    basepow[0] = 1;
    for (int i = 1; i < N; i++) basepow[i] = basepow[i - 1] * base % MOD;
    return 0;
}();
ll getHash(int l, int r) {
    ll res = pref[r + 1] - pref[l] * basepow[r - l + 1] % MOD;
    if (res < 0) res += MOD;
    return res;
}
class Solution {
public:
    int distinctEchoSubstrings(string s) {
        int n = s.size();
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] * base % MOD + (s[i] - 'a' + 1);
            if (pref[i + 1] >= MOD) pref[i + 1] -= MOD;
        }
        int ans = 0;
        unordered_set<ll> S;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++) if (!((j - i + 1) & 1)) {
                int k = (i + j)/2;
                ll cur = getHash(i, k);
                if (cur == getHash(k + 1, j)) S.insert(cur);
            }
        return S.size();
    }
};