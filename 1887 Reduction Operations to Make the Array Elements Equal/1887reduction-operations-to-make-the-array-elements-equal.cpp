class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long long res = 0;
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (nums[i] != nums[i + 1]) res += nums.size() - (i + 1);
        }
        return res;
    }
};