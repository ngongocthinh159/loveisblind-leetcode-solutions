class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        vector<int> dp(nums.size());
        dp[nums.size() - 1] = nums[nums.size() - 1];
        deque<int> q;
        q.push_front(nums.size() - 1);

        for (int i = nums.size() - 2; i >= 0; i--) {
            int startIndex = i + 1;
            int endIndex = min(i + k, (int) nums.size() - 1);

            while (q.size() > 0 && q.front() > endIndex) q.pop_front();
            dp[i] = nums[i] + dp[q.front()];
            while (q.size() > 0 && dp[q.back()] <= dp[i]) q.pop_back();
            q.push_back(i);
        }

        return dp[0];
    }
};