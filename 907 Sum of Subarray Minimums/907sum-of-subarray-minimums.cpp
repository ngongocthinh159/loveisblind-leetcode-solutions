using ll = long long;
const int MOD = 1e9 + 7;

class Solution {
public:
    int sumSubarrayMins(vector<int>& nums) {
        vector<int> dp(nums.size() + 1, 0);
        vector<int> firstSmallerLeft(nums.size());
        stack<int> stack;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            while (stack.size() && !(nums[i] > nums[stack.top()])) {
                stack.pop();
            }
            firstSmallerLeft[i] = stack.size() ? stack.top() : -1;
            stack.push(i);

            int j = firstSmallerLeft[i] + 1;
            dp[i + 1] = dp[j] + (i + 1 - j)*nums[i];
            ans = (ans + dp[i + 1])%MOD;
        }
        return ans;
    }
};