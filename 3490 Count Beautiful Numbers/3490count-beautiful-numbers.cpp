#define ll long long
#define MAX 81
ll dp[2][9][MAX + 1][MAX + 1][MAX + 1];
class Solution {
public:
    ll dfs(int smaller, int i, int prod_mod, int sum, int target_sum, string &s) {
        if (i == s.size())
            return sum == target_sum && prod_mod == 0;
        if (dp[smaller][i][prod_mod][sum][target_sum] != -1)
            return dp[smaller][i][prod_mod][sum][target_sum];
        int r = smaller ? 9 : s[i] - '0';
        ll res = 0;
        for (int j = 0; j <= r && j + sum <= target_sum; j++) {
            int nxt_mod = (sum == 0 && j != 0 ? j % target_sum : prod_mod * (j % target_sum) % target_sum);
            res += dfs(smaller | (j < r), i + 1, nxt_mod, sum + j, target_sum, s);
        }
        return dp[smaller][i][prod_mod][sum][target_sum] = res;
    }
    void clear(int mx_len) {
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < mx_len; j++)
                for (int k = 0; k <= mx_len*9; k++)
                    for (int p = 0; p <= mx_len*9; p++)
                        for (int m = 0; m <= mx_len*9; m++)
                            dp[i][j][k][p][m] = -1;
    }
    int beautifulNumbers(int l, int r) {
        string _r = to_string(r);
        string _l = to_string(l - 1);
        ll ans = 0;
        int r_size = _r.size();
        int l_size = _l.size();
        clear(r_size);
        for (int sum = 1; sum <= r_size*9; sum++) {
            ans += dfs(0,0,0,0,sum,_r);
        }
        clear(l_size);
        for (int sum = 1; sum <= l_size*9; sum++) {
            ans -= dfs(0,0,0,0,sum,_l);
        }
        return ans;
    }
};