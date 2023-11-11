class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> minProd(nums.size(), -1);
        vector<int> maxProd(nums.size(), -1);
        minProd[0] = nums[0];
        maxProd[0] = nums[0];
        int res = INT_MIN;
        for (int i = 1; i < nums.size(); i++) {
            minProd[i] = min(nums[i], min(maxProd[i - 1]*nums[i], minProd[i - 1]*nums[i]));
            maxProd[i] = max(nums[i], max(maxProd[i - 1]*nums[i], minProd[i - 1]*nums[i]));
            res = max(res, maxProd[i]);
        }
        res = max(res, maxProd[0]);
        return res;
    }
};