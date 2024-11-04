int dp[105][105][27][105];
class Solution {
public:
    vector<int> v = {1,9,99};
    string s;
    int dfs(int i, int j, int c, int k) {
        if (i == s.size()) return 0;
        if (dp[i][j][c][k] != -1) return dp[i][j][c][k];

        int idx = -1;
        for (int m = 0; m < v.size(); m++) if (v[m] == j) idx = m;
        int res = INT_MAX;
        // delete
        if (k > 0) res = min(res, dfs(i + 1, j, c, k - 1));

        // hold
        int tmp = dfs(i + 1, c == (s[i] - 'a') ? j + 1 : 1, s[i] - 'a', k);
        if (tmp != INT_MAX) res = min(res, tmp + ((s[i] - 'a') != c ? 1 : (idx != -1 ? 1 : 0)));
        
        return dp[i][j][c][k] = res;
    }
    int getLengthOfOptimalCompression(string ss, int k) {
        s = ss;
        for (int i = 0; i < s.size(); i++) {
            for (int j = 0; j < s.size() + 1; j++) {
                for (int p = 0; p < 27; p++) {
                    for (int m = 0; m < k + 1; m++) {
                        dp[i][j][p][m] = -1;
                    }
                }
            }
        }
        return dfs(0, 0, 26, k);
    }
};