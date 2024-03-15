class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int left = 1;
        vector<int> prfr(n);
        vector<int> ans(n);
        for (int i = n - 1; i >= 0; i--) {
            ans[i] = i == n- 1? nums[i]: nums[i]*ans[i+1];
        }
        for (int i = 0; i < n; i++) {
            ans[i] = left*(i+1<n?ans[i+1]:1);
            left *= nums[i];
        }
        return ans;
    }
};