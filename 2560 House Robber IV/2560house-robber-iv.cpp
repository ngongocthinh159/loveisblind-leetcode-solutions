class Solution {
public:
    bool check(int x, vector<int> &nums, int k) {
        int n = nums.size(), i = 0, cnt = 0;
        while (i < n) {
            if (nums[i] <= x) {
                cnt++;
                i += 2;
            } else
                i++;
        }
        return cnt >= k;
    }
    int minCapability(vector<int>& nums, int k) {
        int l = *min_element(nums.begin(), nums.end()) - 1, r = *max_element(nums.begin(), nums.end());
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