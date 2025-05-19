class Solution {
public:
    string triangleType(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if (nums[0] + nums[1] <= nums[2]) return "none";
        int cnt = 0;
        if (nums[0] == nums[1]) cnt++;
        if (nums[1] == nums[2]) cnt++;
        if (cnt == 1) return "isosceles";
        if (cnt == 2) return "equilateral";
        return "scalene";
    }
};