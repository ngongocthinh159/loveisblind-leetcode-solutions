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
    int n;
    int longestDecomposition(string s) {
        n = s.size();
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] * base % MOD + (s[i] - 'a' + 1);
            if (pref[i + 1] >= MOD) pref[i + 1] -= MOD;
        }
        int mid = (n - 1)/2;
        if (n&1) mid--;
        int ans = 0;
        for (int i = 0; i <= (n - 1)/2;) {
            bool f = false;
            for (int j = i; j <= mid; j++) {
                int ii = n - 1 - j;
                int jj = n - 1 - i;
                if (getHash(i, j) == getHash(ii, jj)) {
                    ans += 2;
                    i = j + 1;
                    f = true;
                    break;
                }
            }
            if (!f) {
                ans += 1;
                break;
            }
        }
        return ans;
    }
};