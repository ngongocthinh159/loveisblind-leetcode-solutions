class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        for (int sum = 0; sum < k; sum++) {
            vector<int> len(k);
            for (int j = 0; j < n; j++) {
                int tar = ((sum - nums[j]) % k + k) % k;
                len[nums[j] % k] = 1 + len[tar];
                ans = max(ans, len[nums[j] % k]);
            }
        }
        return ans;
    }
};