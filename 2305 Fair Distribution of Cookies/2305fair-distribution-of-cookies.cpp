#define N 8
int sum[1 << N];
class Solution {
public:
    int distributeCookies(vector<int>& cookies, int k) {
        int n = cookies.size();
        const int IINF = 1e9 + 5;
        vector<vector<int>> dp(k + 1, vector<int>(1 << n, IINF));
        int nMask = (1 << n) - 1;
        for (int mask = 0; mask <= nMask; mask++) {
            if (mask) {
                int msb = 32 - __builtin_clz(mask) - 1;
                sum[mask] = sum[mask ^ (1 << msb)] + cookies[msb];
            }
        }
        dp[0][0] = 0;
        for (int i = 1; i <= k; i++)
            for (int mask = 0; mask <= nMask; mask++)
                for (int submask = mask; ; submask = (submask - 1) & mask) {
                    if (submask != mask)
                        dp[i][mask] = min(dp[i][mask], max(dp[i - 1][submask], sum[submask ^ mask]));
                    if (!submask) break;
                }
                
        return dp[k][nMask];
    }
};