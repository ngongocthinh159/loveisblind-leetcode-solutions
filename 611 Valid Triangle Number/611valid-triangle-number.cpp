class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), ans = 0;
        for (int i = 0; i < n - 2; i++) {
            int k = i + 2;
            for (int j = i + 1; j < n - 1; j++) {
                k = max(k, j + 1);
                while (k < n && nums[k] < nums[i] + nums[j]) k++;
                ans += k - j - 1;
            }
        }
        return ans;
    }
};