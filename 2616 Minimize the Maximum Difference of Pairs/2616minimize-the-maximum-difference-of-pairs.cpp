class Solution {
public:
    bool check(int limit, vector<int> &nums, int k) {
        int cnt = 0, n = nums.size();
        for (int i = 0; i < n - 1; i ++) {
            if (nums[i + 1] - nums[i] <= limit) cnt++, i++;
        }
        return cnt >= k;
    }
    int minimizeMax(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int l = -1, r = nums.back() - nums[0] + 1;
        while (r - l > 1) {
            int m = l + (r - l)/2;
            if (check(m, nums, k))
                r = m;
            else
                l = m;
        }
        return r;
    }
};