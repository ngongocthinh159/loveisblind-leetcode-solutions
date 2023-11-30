class Solution {
public:
    vector<vector<int>> dp;
    int minimumOneBitOperations(int n) {
        if (n == 0) return 0;
        string s = "";
        while (n) {
            if (n & 1)  s += "1";
            else s += "0";
            n = n >> 1;
        }
        reverse(s.begin(), s.end());
        dp = vector<vector<int>>(s.size(), vector<int>(2, -1));
        return dfs(s, 0, 0);
    }

    // state : 0 - change to 0, all zeros
    // state : 1 - change to 1, all zeros
    int dfs(string s, int i, int state) {
        if (i == s.size() - 1) {
            if ((state == 0 && s[i] == '0') || (state == 1 && s[i] == '1')) return 0;
            else return 1;
        }
        if (dp[i][state] != -1) return dp[i][state];

        int res = 0;
        if (state == 0) {
            if (s[i] == '0') res = dfs(s, i + 1, 0);
            else if (s[i] == '1') res = 1 + dfs(s, i + 1, 1) + pow(2, s.size() - i - 1) - 1;
        } else if (state == 1) {
            if (s[i] == '0') {
                res = 1 + dfs(s, i + 1, 1) + pow(2, s.size() - i - 1) - 1;
            } else if (s[i] == '1') res = dfs(s, i + 1, 0);
        }
        return dp[i][state] = res;
    }
};