class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        sort(nums.begin(), nums.end());
        for (int r = 0, l = 0; r < n; r++) {
            while (l <= r && nums[r] - nums[l] > 1) l++;
            if (nums[r] != nums[l])
                ans = max(ans, r - l + 1); 
        }
        return ans;
    }
};