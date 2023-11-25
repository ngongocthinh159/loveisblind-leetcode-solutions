class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int sum = 0;
        vector<int> pre(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++) {
            pre[i] = i == 0 ? nums[i] : nums[i] + pre[i - 1];
        }
        vector<int> res(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++) {
            int l1 = 0, l2 = i - 1;
            int r1 = i + 1, r2 = nums.size() - 1;
            if (l1 <= l2) {
                res[i] += (l2 - l1 + 1)*nums[i] - (pre[l2] - pre[l1] + nums[l1]);
            }
            if (r1 <= r2) {
                res[i] += pre[r2] - pre[r1] + nums[r1] - (r2 - r1 + 1)*nums[i];
            }
        }
        return res;
    }
};