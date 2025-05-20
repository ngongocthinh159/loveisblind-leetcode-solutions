class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> dif(n + 1);
        for (auto &q : queries) {
            dif[q[0]] += 1;
            dif[q[1] + 1] -= 1;
        }
        for (int i = 0; i < n; i++) dif[i + 1] += dif[i];
        for (int i = 0; i < n; i++) if (dif[i] - nums[i] < 0) return false;
        return true;
    }
};