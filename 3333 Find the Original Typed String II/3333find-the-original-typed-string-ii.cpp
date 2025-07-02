#define ll long long
#define N 500005
#define K 2005
int cnt[N];
ll dp[K], ndp[K];
ll pref[K], npref[K];
const int MOD = 1e9 + 7;
class Solution {
public:
    void clear(ll *arr, int sz) {
        memset(arr, 0, sz * sizeof(int));
        // for (int i = 0; i < sz; i++) arr[i] = 0;
    }
    int possibleStringCount(string word, int k) {
        int n = word.size();
        int top = 0;
        for (int i = 0; i < n; ) {
            char c = word[i];
            int s = i, e = i;
            while (i < n && c == word[i]) e = i, i++;
            cnt[top++] = e - s + 1;
        }
        if (top >= k) {
            ll tot = 1;
            for (int i = 0; i < top; i++) tot = tot * cnt[i] % MOD;
            return tot;
        }
        clear(dp, k);
        clear(pref, k + 1);
        ll tot = 1;
        dp[0] = 1;
        for (int i = 1; i <= k; i++) pref[i] = 1;
        for (int i = 0; i < top; i++) {
            clear(ndp, k);
            clear(npref, k + 1);
            for (int j = 1; j < k; j++) {
                int l = j - min(j, cnt[i]);
                int r = j - 1;
                ndp[j] = pref[r + 1] - pref[l];
                if (ndp[j] < 0) ndp[j] += MOD;
                npref[j + 1] = npref[j] + ndp[j];
                if (npref[j + 1] >= MOD) npref[j + 1] -= MOD;
            }
            swap(dp, ndp);
            swap(pref, npref);
            tot = tot * cnt[i] % MOD;
        }
        ll ans = tot;
        for (int j = 1; j < k; j++) {
            ans -= dp[j];
            if (ans < 0) ans += MOD;
        }
        return ans;
    }
};