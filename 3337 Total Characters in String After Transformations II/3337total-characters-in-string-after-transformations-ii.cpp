#define ll long long
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
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        int n = 26;
        vector<vector<int>> mat(n, vector<int>(n));
        for (int i = 0; i < n; i++)
            for (int j = 1; j <= nums[i]; j++) mat[i][(i + j)%26] = 1;
        vector<vector<int>> base(n, vector<int>(1, 1));
        auto mat_pow = expo_mat(mat, t);
        auto res = mul_mat(mat_pow, base);
        ll ans = 0;
        for (auto c : s) {
            ans += res[c - 'a'][0];
            if (ans >= MOD) ans -= MOD;
        }
        return ans;
    }
};