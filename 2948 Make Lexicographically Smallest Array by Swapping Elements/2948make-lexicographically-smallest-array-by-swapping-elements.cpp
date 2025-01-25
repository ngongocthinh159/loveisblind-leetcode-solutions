class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int group = -1, n = nums.size();
        vector<int> idx_to_group(n), order(n), res(n), group_to_order_idx(n);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int i, int j) {
            return nums[i] < nums[j];
        });
        int j = 0;
        while (j < n) {
            int prev = nums[order[j]];
            group_to_order_idx[++group] = j;
            while (j < n && nums[order[j]] - prev <= limit) {
                idx_to_group[order[j]] = group;
                prev = nums[order[j]];
                j++;
            }
        }
        for (int i = 0; i < n; i++) {
            res[i] = nums[order[group_to_order_idx[idx_to_group[i]]++]];
        }
        return res;
    }
};