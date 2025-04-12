#define ll long long
#define N 12
const ll base = 13;
const int MOD = 1e9 + 7;
ll tenpow[N], per[N], basepow[N];
int freq[10]{};
auto init = []{
    tenpow[0] = 1;
    for (int i = 1; i < N; i++) tenpow[i] = tenpow[i - 1] * 10;
    per[0] = 1;
    for (int i = 1; i < N; i++) per[i] = per[i - 1] * i;
    basepow[0] = 1;
    for (int i = 1; i < N; i++) basepow[i] = basepow[i - 1] * base;
    return 0;
}();
class Solution {
public:
    unordered_set<int> S;
    ll ans = 0, _n;
    int get_hash(ll x) {
        ll res = 0;
        for (int i = 0; i <= 9; i++) if (freq[i]) {
            res = res + freq[i] * basepow[i];
            if (res >= MOD) res -= MOD;
        }
        return res;
    }
    void dfs(int i, ll cur, int n, int k) {
        if (i >= (n + 1)/2) {
            if (cur % k == 0) {
                int cur_hash = get_hash(cur);
                if (!S.count(cur_hash)) {
                    S.insert(cur_hash);
                    ans += cal(cur);
                }
            }
            return;
        }
        int sym_i = n - 1 - i;
        for (int j = (i == 0 ? 1 : 0); j <= 9; j++) {
            if (i == sym_i) {
                freq[j]++;
                dfs(i + 1, cur + j * tenpow[n - i - 1], n, k);
                freq[j]--;
            }
            else {
                freq[j] += 2;
                dfs(i + 1, cur + j * tenpow[n - i - 1] + j * tenpow[n - sym_i - 1], n, k);
                freq[j] -= 2;
            }
        }
    }
    ll cnt_permutation(int len) {
        ll ans = per[len];
        for (int i = 0; i <= 9; i++) ans /= per[freq[i]];
        return ans;
    }
    ll cal(ll x) {
        ll ans = cnt_permutation(_n);
        if (freq[0] >= 1) {
            freq[0]--;
            ans -= cnt_permutation(_n - 1);
            freq[0]++;
        }
        return ans;
    }
    long long countGoodIntegers(int n, int k) {
        _n = n;
        dfs(0, 0, n, k);
        return ans;
    }
};