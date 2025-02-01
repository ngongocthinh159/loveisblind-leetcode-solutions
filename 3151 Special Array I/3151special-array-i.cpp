class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        bool ans = true;
        for (int i = 1; i < nums.size(); i++) ans &= (nums[i]&1) ^ (nums[i - 1]&1);
        return ans;
    }
};