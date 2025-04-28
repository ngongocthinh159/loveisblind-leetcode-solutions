class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        vector<long long> pref(n + 1);
        long long ans = 0;
        for (int r = 0, l = 0; r < n; r++) {
            pref[r + 1] = pref[r] + nums[r];
            while (l <= r && 1LL * (pref[r + 1] - pref[l]) * (r - l + 1) >= k) {
                l++;
            }
            ans += (r - l + 1);
        }
        return ans;
    }
};