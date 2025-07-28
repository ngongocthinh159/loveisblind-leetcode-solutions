class Solution {
public:
    int xsum = 0;
    int cnt = 0;
    void dfs(int i, int cxor, vector<int> &nums) {
        if (i == nums.size()) {
            if (cxor == xsum) cnt++;
            return;
        }
        dfs(i + 1, cxor, nums);
        dfs(i + 1, cxor | nums[i], nums);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        for (auto x : nums) xsum |= x;
        dfs(0, 0, nums);
        if (xsum == 0) cnt--;
        return cnt;
    }
};