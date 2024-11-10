class Solution {
public:
    const int LOG = 20;
    int query(int l, int r, vector<vector<int>> &v) {
        int len = r - l + 1;
        int msb = 32 - __builtin_clz(len) - 1;
        return v[msb][l] | v[msb][r - (1 << msb) + 1];
    }
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> orRange(LOG + 1, vector<int>(n));
        for (int i = 0; i < n; i++) orRange[0][i] = nums[i];
        for (int j = 1; j <= LOG; j++) {
            for (int i = 0; i < n; i++) {
                if (i + (1 << j) - 1 < n) orRange[j][i] = orRange[j - 1][i] | orRange[j - 1][i + (1 << (j - 1))];
            }
        }
        int l = 0, r = 0;
        int ans = INT_MAX;
        while (r < n) {
            int cur = query(l, r, orRange);

            while (l <= r && cur >= k) {
                ans = min(ans, r - l + 1);
                l++;
                if (l <= r) cur = query(l, r, orRange);
            }

            r++;
        }
        return ans == INT_MAX ? -1 : ans;
    }
};