#define MAXN 100005
long long dp[MAXN];
class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        dp[n] = 0;
        for (int i = n - 1; i >= 0; i--) {
            dp[i] = dp[min(n, i + questions[i][1] + 1)] + questions[i][0];
            dp[i] = max(dp[i], dp[i + 1]);
        }
        return dp[0];
    }
};