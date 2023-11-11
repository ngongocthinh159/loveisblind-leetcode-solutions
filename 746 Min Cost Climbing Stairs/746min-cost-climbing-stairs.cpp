class Solution {
public:
    vector<int> dp;
    int minCostClimbingStairs(vector<int>& cost) {
        dp = vector<int>(cost.size(), -1);
        return min(explore(cost, 0), explore(cost, 1));
    }

    int explore(vector<int>& cost, int i) {
        if (i >= cost.size()) {
            return 0;
        }
        if (dp[i] != -1) return dp[i];

        return dp[i] = cost[i] + min(explore(cost, i + 1), explore(cost, i + 2));
    }
};