class Solution {
public:
    const int mod = 1e9 + 7;
    int checkRecord(int n) {
        vector<vector<int>> prev(3, vector<int>(2, 1));
        for (int i = n - 1; i >= 0; i--) {
            vector<vector<int>> cur(3, vector<int>(2, 0));
            for (int j = 3 - 1; j >= 0; j--) {
                for (int k = 2 - 1; k >= 0; k--) {
                    cur[j][k] = (cur[j][k] + prev[0][k]) % mod;
                    if (k == 0) cur[j][k] = (cur[j][k] + prev[0][k + 1]) % mod;
                    if (j == 0 || j == 1) cur[j][k] = (cur[j][k] + prev[j + 1][k]) % mod;
                }
            }

            prev = cur;
        }
        return prev[0][0];
    }
};