class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int cnt = 0, i = 0;
        for (auto x : nums) if (x == pivot) cnt++;
        vector<int> res(nums.size());
        for (auto x : nums) if (x < pivot) res[i++] = x;
        while (cnt--) res[i++] = pivot;
        for (auto x : nums) if (x > pivot) res[i++] = x;
        return res;
    }
};