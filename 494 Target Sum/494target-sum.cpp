class Solution {
public:
    const int offset = 1000;
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> cur(2000 + 1, 0), prev(2000 + 1, 0);
        prev[0 + offset] = 1;
        for (int i = 1; i <= n; i++) {
            for (int tar = -1000; tar <= 1000; tar++) {
                cur[tar + offset] = 0;
                if (-1000 <= tar + nums[i - 1] && tar + nums[i - 1] <= 1000)
                    cur[tar + offset] += prev[tar + nums[i - 1] + offset];
                if (-1000 <= tar - nums[i - 1] && tar - nums[i - 1] <= 1000)
                    cur[tar + offset] += prev[tar - nums[i - 1] + offset];
            }
            prev = cur;
        }
        return cur[target + offset];
    }
};