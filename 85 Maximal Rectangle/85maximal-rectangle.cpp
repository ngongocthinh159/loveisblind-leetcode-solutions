class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<pair<int,int>>> dp(n,
            vector<pair<int,int>>(m, {0, 0}));
        vector<vector<pair<int,int>>> dp2(n,
            vector<pair<int,int>>(m, {0, 0}));
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '0') continue;
                int w = INT_MAX;
                if (j > 0) w = min(w, dp[i][j - 1].first);
                if (i > 0 && j > 0) w = min(w, dp[i - 1][j - 1].first);
                if (w == INT_MAX) w = 0;
                int h = INT_MAX;
                if (i > 0) h = min(h, dp[i - 1][j].second);
                if (i > 0 && j > 0) h = min(h, dp[i - 1][j - 1].second);
                if (h == INT_MAX) h = 0;
                dp[i][j] = {1 + w, 1 + h};

                dp2[i][j] = {1, 1};
                if (j > 0) dp2[i][j].second = dp2[i][j].second + dp2[i][j - 1].second;
                if (i > 0) dp2[i][j].first = dp2[i][j].first + dp2[i - 1][j].first;

                ans = max(ans, dp[i][j].first*dp[i][j].second);
                ans = max(ans, dp2[i][j].first);
                ans = max(ans, dp2[i][j].second);
            }
        }
        return ans;
    }
};