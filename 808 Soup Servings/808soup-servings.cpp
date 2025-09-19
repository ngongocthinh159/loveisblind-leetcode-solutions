#define N 4450
double dp1[N][N], dp2[N][N];
auto init = [] {
    for (int i = 1; i < N; i++) dp1[0][i] = 1;
    dp2[0][0] = 1;
    for (int i = 1; i < N; i++)
        for (int j = 1; j < N; j++) {
            dp1[i][j] = 0.25 * (
                dp1[max(0, i - 100)][j] +
                dp1[max(0, i - 75)][max(0, j - 25)] + 
                dp1[max(0, i - 50)][max(0, j - 50)] +
                dp1[max(0, i - 25)][max(0, j - 75)]
            );
            dp2[i][j] = 0.25 * (
                dp2[max(0, i - 100)][j] +
                dp2[max(0, i - 75)][max(0, j - 25)] + 
                dp2[max(0, i - 50)][max(0, j - 50)] +
                dp2[max(0, i - 25)][max(0, j - 75)]
            );
        }
    return 0;
}();
class Solution {
public:
    double soupServings(int n) {
        if (n > N) return 1;
        return dp1[n][n] + 0.5 * dp2[n][n];
    }
};