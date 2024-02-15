class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long long sum = nums[0] + nums[1];
        long long ans = -1;
        for (int i = 2; i < nums.size(); i++) {
            if (sum > nums[i]) {
                ans = max(ans, sum + nums[i]);
            }
            sum += nums[i];
        }
        return ans;
    }
};