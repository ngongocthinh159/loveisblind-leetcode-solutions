class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int l = 0;
        vector<int> ans;
        for (int r = 0; r < nums.size(); r++) {
            if (r != 0 && !(nums[r] == nums[r - 1] + 1)) l = r;
            if (r >= k - 1) {
                if (r - l + 1 >= k) ans.push_back(nums[r]);
                else ans.push_back(-1);
            }
        }
        return ans;
    }
};