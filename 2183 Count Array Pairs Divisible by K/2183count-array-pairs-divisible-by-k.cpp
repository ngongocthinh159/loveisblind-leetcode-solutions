class Solution {
public:
    long long countPairs(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = 0;
        unordered_map<int,long long> freq;
        for (int i = 0; i < n; i++) {
            long long gcd = __gcd(nums[i], k);
            for (auto &[gcd2, cnt] : freq) if (gcd * gcd2 % k == 0)
                ans += cnt;
            freq[gcd]++;
        }
        return ans;
    }
};