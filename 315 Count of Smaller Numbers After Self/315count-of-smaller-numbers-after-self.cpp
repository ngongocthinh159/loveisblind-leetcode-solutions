class Solution {
public:
    vector<pair<int,int>> buf;
    void dfs(int l, int r, vector<pair<int,int>>& nums, vector<int> &res) {
        if (l >= r) return;
        int m = (l + r)/2;
        dfs(l, m, nums, res);
        dfs(m + 1, r, nums, res);
        for (int i = m, j = r; i >= l; i--) {
            while (j >= m + 1 && nums[j].first >= nums[i].first) j--;
            res[nums[i].second] += j - (m + 1) + 1;
        }
        merge(l, r, nums);
    }
    void merge(int l, int r, vector<pair<int,int>> &nums) {
        int m = (l + r)/2;
        int i = l, j = m + 1, k = l;
        while (i <= m && j <= r) {
            if (nums[i].first <= nums[j].first) 
                buf[k++] = nums[i++];
            else
                buf[k++] = nums[j++];
        }
        while (i <= m) buf[k++] = nums[i++];
        while (j <= r) buf[k++] = nums[j++];
        for (int p = l; p <= r; p++) nums[p] = buf[p];
    }
    vector<int> countSmaller(vector<int>& nums) {
        buf.resize(nums.size());
        vector<int> res(nums.size());
        vector<pair<int,int>> arr(nums.size());
        for (int i = 0; i < nums.size(); i++) arr[i] = {nums[i], i};
        dfs(0, nums.size() - 1, arr, res);
        return res;
    }
};