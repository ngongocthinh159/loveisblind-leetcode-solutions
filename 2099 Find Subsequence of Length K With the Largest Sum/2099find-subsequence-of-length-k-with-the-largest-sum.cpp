class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> order(n);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&] (int i, int j) {
            return nums[i] > nums[j];
        });
        vector<int> res(order.begin(), order.begin() + k);
        sort(res.begin(), res.end());
        for (int i = 0; i < k; i++) res[i] = nums[res[i]];
        return res;
    }
};