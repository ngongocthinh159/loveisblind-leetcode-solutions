class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        dfs(0, nums);
        return res;
    }
    void dfs(int i, vector<int> &nums) {
        if (i == nums.size()) {
            res.push_back(path);
            return;
        }

        if (!path.size() || path.back() != nums[i]) {
            dfs(i + 1, nums);
        }

        path.push_back(nums[i]);
        dfs(i + 1, nums);
        path.pop_back();
    }
};