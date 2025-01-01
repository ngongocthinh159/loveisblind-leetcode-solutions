#define ll long long
class Solution {
public:
    int waysToPartition(vector<int>& nums, int k) {
        unordered_map<ll,int> M1;
        unordered_map<ll,int> M2;
        int n = nums.size();
        vector<ll> pref(n + 1);
        for (int i = 0; i < n; i++) pref[i + 1] = pref[i] + nums[i];
        vector<int> dp(n);
        for (int i = 1; i < n; i++) {
            M1[pref[n] - pref[i] - pref[i]]++;
            int delta = k - nums[i];
            dp[i] += M1[-delta];
        }
        for (int i = n - 2; i >= 0; i--) {
            M2[pref[i + 1] - (pref[n] - pref[i + 1])]++;
            int delta = k - nums[i];
            dp[i] += M2[-delta];
        }
        int ans = 0;
        for (int i = 0; i < n - 1; i++) {
            if (pref[i + 1] == pref[n] - pref[i + 1]) ans++;
        }
        for (int i = 0; i < n; i++) ans = max(ans, dp[i]);
        return ans;
    }
};