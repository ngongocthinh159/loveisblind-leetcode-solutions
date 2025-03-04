#define MAXN 27
#define MAXK 105
double dp[MAXK][MAXN][MAXN];
class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                dp[0][i][j] = 0;
        dp[0][row][column] = 1;
        for (int move = 1; move <= k; move++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++) {
                    dp[move][i][j] = 0;
                    for (auto x : {1,-1,2,-2})
                        for (auto y : {1,-1,2,-2}) if (abs(x) != abs(y)) {
                            int I = i + x;
                            int J = j + y;
                            if (0 <= I && I < n && 0 <= J && J < n)
                                dp[move][i][j] += dp[move - 1][I][J] / 8;
                        }
                }
        double ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) 
                ans += dp[k][i][j];
        return ans;
    }
};