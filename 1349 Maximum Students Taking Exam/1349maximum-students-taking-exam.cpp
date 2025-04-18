#define LSB(S) (S & ~(S - 1))
class Solution {
public:
    bool check(int mask, int i, vector<int> &avail) {
        return ((mask & avail[i]) == mask) && !(mask & (mask >> 1)) && !(mask & (mask << 1));
    }
    int maxStudents(vector<vector<char>>& seats) {
        int n = seats.size(), m = seats[0].size();
        vector<vector<int>> dp(n + 1, vector<int>(1 << m));
        vector<int> avail(n + 1);
        for (int i = 1; i <= n; i++)
            for (int j = 0; j < m; j++) if (seats[i - 1][j] == '.') avail[i] ^= (1 << j);
        int mMask = (1 << m) - 1;
        int ans = 0;
        for (int i = 1; i <= n; i++)
            for (int mask = 0; mask <= mMask; mask++) if (check(mask, i, avail)) {
                for (int pmask = 0; pmask <= mMask; pmask++) if (check(pmask, i - 1, avail)) {
                    if (! (mask&(pmask << 1) || mask&(pmask >> 1))) {
                        int set_bits = mask == 0 ? 0 : __builtin_popcount(mask);
                        dp[i][mask] = max(dp[i][mask], set_bits + dp[i - 1][pmask]);
                    }
                }
                if (i == n) ans = max(ans, dp[i][mask]);
            }
        return ans;
    }
};