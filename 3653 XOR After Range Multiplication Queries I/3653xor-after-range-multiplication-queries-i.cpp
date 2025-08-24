class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), m = queries.size();
        const int MOD = 1e9 + 7;
        for (auto &q : queries) {
            int idx = q[0];
            int r = q[1];
            int k = q[2];
            int v = q[3];
            while (idx <= r) {
                nums[idx] = 1LL * nums[idx] * v % MOD;
                idx += k;
            }
        }
        int ans = nums[0];
        for (int i = 1; i < n; i++) ans ^= nums[i];
        return ans;
    }
};