class Solution {
public:
    vector<long long> psum;
    bool check(int x, vector<int> &nums, int k) {
        for (int r = x - 1; r < nums.size(); r++) {
            long long cost = 1LL*nums[r]*x - (1LL*psum[r] - psum[r - x + 1] + nums[r - x + 1]);
            if (cost <= 1LL*k) return true;
        }
        return false;
    }
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        psum = vector<long long>(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            psum[i] = i == 0 ? nums[i] : 1LL*nums[i] + psum[i - 1];
        }
        int l = 1, r = nums.size(), ans = 1;
        while (l <= r) {
            int m = l + (r - l)/2;
            if (check(m, nums, k)) {
                ans = m;
                l = m + 1;
            } else
                r = m - 1;
        }
        return ans;
    }
};