int dp[305][15];
class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        if (jobDifficulty.size() < d) return -1;
        fill(&dp[0][0], &dp[0][0] + 305*15, -1);
        return dfs(0, d, jobDifficulty);
    }

    int dfs(int i, int d, vector<int> &jd) {
        if (d < 0) return INT_MAX;
        if (i != jd.size() && d == 0) return INT_MAX;
        if (i == jd.size() && d > 0) return INT_MAX;
        if (i == jd.size() && d == 0) return 0;
        if (dp[i][d] != -1) return dp[i][d];

        long long res = INT_MAX;
        int mx = INT_MIN;
        for (int j = i; j <= jd.size() - d; j++) {
            mx = max(mx, jd[j]);
            res = min(res, 1LL*mx + dfs(j + 1, d - 1, jd));
        }
        
        return dp[i][d] = res;
    }
};