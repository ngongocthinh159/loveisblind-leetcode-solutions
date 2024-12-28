#define ll long long
class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<pair<ll,int>> pref(n), sur(n);
        ll cur_window = 0;
        for (int i = 0; i < k; i++) cur_window += nums[i];
        pref[k - 1] = {cur_window, 0};
        ll mx_window = cur_window;
        for (int i = k; i < n; i++) {
            cur_window += nums[i] - nums[i - k];
            if (mx_window < cur_window) {
                mx_window = cur_window;
                pref[i] = {mx_window, i - k + 1};
            } else pref[i] = pref[i - 1];
        }
        cur_window = 0;
        for (int i = n - 1; i > (n - 1 - k); i--) cur_window += nums[i];
        sur[n - k] = {cur_window, n - k};
        mx_window = cur_window;
        for (int i = n - k - 1; i >= 0; i--) {
            cur_window += nums[i] - nums[i + k];
            if (mx_window <= cur_window) {
                mx_window = cur_window;
                sur[i] = {mx_window, i};
            } else sur[i] = sur[i + 1];
        }
        ll mx = 0;
        vector<int> ans;
        cur_window = 0;
        for (int i = 0; i < n; i++) {
            cur_window += nums[i];
            if (i - k >= 0) cur_window -= nums[i - k];
            if (i - k - k + 1 >= 0 && i + k < n) {
                ll cur = pref[i - k].first + cur_window + sur[i + 1].first;
                if (mx < cur) {
                    mx = cur;
                    ans = {pref[i - k].second, i - k + 1, sur[i + 1].second};
                }
            }
        }
        return ans;
    }
};