#define N 100005
#define ll long long
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
    string longestPrefix(string s) {
        int n = s.size();
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] * base % MOD + (s[i] - 'a' + 1);
            if (pref[i + 1] >= MOD) pref[i + 1] -= MOD;
        }
        for (int i = n - 2; i >= 0; i--) {
            int j = (n - 1 - i);
            if (getHash(0, i) == getHash(j, n - 1)) return s.substr(0, i + 1);
        }
        return "";
    }
};