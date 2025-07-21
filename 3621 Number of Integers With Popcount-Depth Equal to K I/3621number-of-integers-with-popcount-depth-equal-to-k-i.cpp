#define BIT 50
int step[BIT + 1];
long long dp[BIT + 1][BIT + 1][2];
auto init = []{
    for (int i = 2; i <= BIT; i++)
        step[i] = step[__builtin_popcount(i)] + 1;
    return 0;
}();
class Solution {
public:
    int len;
    long long dfs(int i, int chosen, bool smaller, int mustChose, string &r) {
        if (chosen == mustChose) return 1;
        if (i == r.size()) return 0;
        if (dp[i][chosen][smaller] != -1) return dp[i][chosen][smaller];
        int upper = smaller ? 1 : r[i] - '0';
        long long res = 0;
        for (int j = 0; j <= upper; j++) {
            res += dfs(i + 1, chosen + (j == 1), smaller | (j < r[i] - '0'), mustChose, r);
        }
        return dp[i][chosen][smaller] = res;
    }
    string toBinaryString(long long x) {
        string res = "";
        while (x) {
            if (x&1)
                res += '1';
            else
                res += '0';
            x >>= 1;
        }
        reverse(res.begin(), res.end());
        return res;
    }
    long long popcountDepth(long long n, int k) {
        if (k == 0) 
            return 1;
        string r = toBinaryString(n);
        len = r.size();
        long long ans = 0;
        for (int i = 1; i <= len; i++) {
            if (step[i] + 1 == k) {
                for (int i = 0; i <= len; i++)
                    for (int j = 0; j <= len; j++)
                        for (int k = 0; k < 2; k++) dp[i][j][k] = -1;
                ans += dfs(0, 0, false, i, r);
            }
        }
        if (k == 1) ans -= 1;
        return ans;
    }
};