class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<vector<int>> mul_mat(vector<vector<int>> &a, vector<vector<int>> &b) {
        int x = a.size(), y = a[0].size(), z = b[0].size();
        vector<vector<int>> res(x, vector<int>(z));
        for (int i = 0; i < x; i++) 
            for (int k = 0; k < y; k++)
                for (int j = 0; j < z; j++) {
                    res[i][j] += 1LL * a[i][k] * b[k][j] % MOD;
                    if (res[i][j] >= MOD) res[i][j] -= MOD;
                }
        return res;
    }
    vector<vector<int>> expo_mat(vector<vector<int>> &mat, int p) {
        int n = mat.size();
        vector<vector<int>> res(n, vector<int>(n));
        for (int i = 0; i < n; i++) res[i][i] = 1;
        vector<vector<int>> cur = mat;
        while (p) {
            if (p&1) {
                res = mul_mat(res, cur);
            }
            cur = mul_mat(cur, cur);
            p >>= 1;
        }
        return res;
    }
    int knightDialer(int n) {
        int N = 10;
        vector<vector<int>> mat = {
            {0, 0, 0, 0, 0, 1, 0, 1, 0, 0}, // 0 -> 5, 7
            {0, 0, 0, 0, 0, 0, 1, 0, 1, 0}, // 1 -> 6, 8
            {0, 0, 0, 1, 0, 0, 0, 1, 0, 0}, // 2 -> 3, 7
            {0, 0, 1, 0, 0, 0, 0, 0, 1, 1}, // 3 -> 2, 8, 9
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 4 -> 2, 8, 9
            {1, 0, 0, 0, 0, 0, 1, 0, 0, 1}, // 5 -> 0, 6, 9
            {0, 1, 0, 0, 0, 1, 0, 0, 0, 0}, // 6 -> 1, 5
            {1, 0, 1, 0, 0, 0, 0, 0, 0, 0}, // 7 -> 0, 2
            {0, 1, 0, 1, 0, 0, 0, 0, 0, 0}, // 8 -> 1, 3
            {0, 0, 0, 1, 0, 1, 0, 0, 0, 0}, // 9 -> 3, 5
        };
        vector<vector<int>> base(N, vector<int>(1, 1));
        auto mat_pow = expo_mat(mat, n - 1);
        auto res = mul_mat(mat_pow, base);
        int ans = 0;
        for (int i = 0; i < N; i++) {
            ans += res[i][0];
            if (ans >= MOD) ans -= MOD;
        }
        return ans;
    }
};