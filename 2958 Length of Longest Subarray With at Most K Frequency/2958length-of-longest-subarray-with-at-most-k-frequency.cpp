class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int l = 0, r = 0;
        bool good = true;
        int ans = 0;
        while (r < n) {
            int cnt = ++mp[nums[r]];
            if (cnt > k) {good = false;}

            while (l <= r && !good) {
                int cnt2 = --mp[nums[l]];
                if (cnt2 == k) good = true;
                l++;
            }

            ans = max(ans, r - l + 1);

            r++;
        }
        return ans;
    }
};