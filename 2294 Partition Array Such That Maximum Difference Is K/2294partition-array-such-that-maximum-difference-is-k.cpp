class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int i = 0, ans = 0;
        while (i < n) {
            int x = nums[i];
            while (i < n && nums[i] - x <= k) {
                i++;
            }
            ans++;
        }
        return ans;
    }
};