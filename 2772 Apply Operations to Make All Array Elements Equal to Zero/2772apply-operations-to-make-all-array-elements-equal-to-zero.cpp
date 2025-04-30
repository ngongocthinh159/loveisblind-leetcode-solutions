class Solution {
public:
    bool checkArray(vector<int>& nums, int k) {
        int n = nums.size(), cur = 0;
        vector<int> effect(n + 1);
        for (int i = 0; i <= n - k; i++) {
            cur += effect[i];
            int dif = nums[i] - cur;
            if (dif < 0) return false;
            effect[i + k] -= dif;
            cur += dif;
        }
        for (int i = n - k + 1; i < n; i++) {
            cur += effect[i];
            if (nums[i] != cur)
                return false;
        }
        return true;
    }
};