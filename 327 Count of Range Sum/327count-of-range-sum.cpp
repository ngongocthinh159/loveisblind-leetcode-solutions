#define ll long long
#define N 100005
ll pref[N], buf[N];
class Solution {
public:
    void dfs(int l, int r, int upper, ll &ans) {
        if (l >= r) return;
        int m = (l + r)/2;
        dfs(l, m, upper, ans);
        dfs(m + 1, r, upper, ans);
        for (int i = m + 1, j = l; i <= r; i++) {
            while (j <= m && pref[j] < pref[i] - upper) j++;
            ans += m - j + 1;
        }
        merge(l, r);
    }
    void merge(int l, int r) {
        int m = (l + r)/2;
        int i = l, j = m + 1, k = l;
        while (i <= m && j <= r) {
            if (pref[i] <= pref[j]) 
                buf[k++] = pref[i++];
            else 
                buf[k++] = pref[j++];
        }
        while (i <= m) buf[k++] = pref[i++];
        while (j <= r) buf[k++] = pref[j++];
        for (int p = l; p <= r; p++) 
            pref[p] = buf[p];
    }
    ll helper(vector<int> &nums, int upper) {
        ll ans = 0;
        for (int i = 0; i < nums.size(); i++) pref[i] = 1LL*nums[i] + (i - 1 >= 0 ? pref[i - 1] : 0);
        dfs(0, nums.size() - 1, upper, ans);
        for (int i = 0; i < nums.size(); i++) if (pref[i] <= upper) ans++;
        return ans;
    }
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        return helper(nums, upper) - helper(nums, lower - 1);
    }
};