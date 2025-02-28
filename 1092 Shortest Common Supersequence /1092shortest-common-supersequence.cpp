#define MAXN 1005
int dp[MAXN][MAXN];
int trace[MAXN][MAXN][3];
class Solution {
public:
    bool maximize(int &x, int y) {
        if (x < y) {
            x = y;
            return true;
        }
        return false;
    }
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= m; j++) {
                dp[i][j] = 0;
                for (int k = 0; k < 3; k++) 
                    trace[i][j][k] = -1;
            }
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) {
                if (str1[i - 1] == str2[j - 1]) {
                    if (maximize(dp[i][j], 1 + dp[i - 1][j - 1])) {
                        trace[i][j][0] = i - 1;
                        trace[i][j][1] = j - 1;
                        trace[i][j][2] = str1[i - 1] - 'a';
                    }
                }
                else {
                    if (maximize(dp[i][j], dp[i - 1][j])) {
                        for (int k = 0; k < 3; k++)
                            trace[i][j][k] = trace[i - 1][j][k];
                    }
                    if (maximize(dp[i][j], dp[i][j - 1])) {
                        for (int k = 0; k < 3; k++)
                            trace[i][j][k] = trace[i][j - 1][k];
                    }
                }
            }
        int bestI = n, bestJ = m;
        string lcs = "";
        while (trace[bestI][bestJ][0] != -1) {
            int prevI = trace[bestI][bestJ][0];
            int prevJ = trace[bestI][bestJ][1];
            lcs += trace[bestI][bestJ][2] + 'a';
            bestI = prevI;
            bestJ = prevJ;
        }
        reverse(lcs.begin(), lcs.end());
        string res = "";
        int j = 0, k = 0;
        for (int i = 0; i < lcs.size(); i++) {
            while (j < str1.size() && str1[j] != lcs[i]) {
                res += str1[j++];
            }
            j++;
            while (k < str2.size() && str2[k] != lcs[i]) {
                res += str2[k++];
            }
            k++;

            res += lcs[i];
        }
        while (j < n) res += str1[j++];
        while (k < m) res += str2[k++];

        return res;
    }
};