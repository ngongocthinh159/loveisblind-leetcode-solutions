class Solution {
public:
    bool check(int mx_sum, vector<int> &nums, int k) {
        int cnt = 0;
        int i = 0, n = nums.size();
        while (i < n) {
            int sum = 0;
            while (i < n && sum + nums[i] <= mx_sum) {
                sum += nums[i];
                i++;
            }
            cnt++;
        }
        return cnt <= k;
    }
    int splitArray(vector<int>& nums, int k) {
        int l = *max_element(nums.begin(), nums.end()) - 1, r = 1e9 + 1;
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