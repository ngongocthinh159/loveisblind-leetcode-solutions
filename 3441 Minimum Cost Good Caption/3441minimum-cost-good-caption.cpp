int dp[50005][4][26], trace[50005][4][26];
int minimize(int& x, int y) {
    if (x > y) {
        x = y;
        return true;
    }
    return false;
}
class Solution {
public:
    int n;
    const int IINF = 1e9;
    int dfs(int i, int rep, int prev_c, string &caption) {
        if (i == n)
            return dp[i][rep][prev_c] = rep < 3 ? IINF : 0;
        if (dp[i][rep][prev_c] != -1) 
            return dp[i][rep][prev_c];
        int res = IINF;
        if (i == 0) {
            for (int c = 0; c < 26; c++) {
                if (minimize(res, dfs(i + 1, 1, c, caption) + abs(caption[i] - 'a' - c)))
                    trace[i][rep][prev_c] = (1 << 10) ^ (c << 5) ^ (c << 0);
            }
        } else {
            if (rep < 3) {
                res = dfs(i + 1, rep + 1, prev_c, caption) + abs(caption[i] - 'a' - prev_c);
                trace[i][rep][prev_c] = ((rep + 1) << 10) ^ (prev_c << 5) ^ (prev_c << 0);
            } else {
                for (int c = 0; c < 26; c++) {
                    int nrep = c == prev_c ? rep : 1;
                    if (minimize(res, dfs(i + 1, nrep, c, caption) + abs(caption[i] - 'a' - c)))
                        trace[i][rep][prev_c] = (nrep << 10) ^ (c << 5) ^ (c << 0);
                }
            }
        }
        return dp[i][rep][prev_c] = res;
    }
    string minCostGoodCaption(string caption) {
        n = caption.size();
        if (n <= 2) return "";
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= 3; j++)
                for (int c = 0; c < 26; c++) dp[i][j][c] = -1;
        dfs(0, 0, 0, caption);
        string res = "";
        int bestRep = 0, bestPrev_c = 0;
        for (int i = 0; i < n; i++) {
            int c = ((1 << 5) - 1) & trace[i][bestRep][bestPrev_c];
            int nbestPrev_c = ((1 << 5) - 1) & (trace[i][bestRep][bestPrev_c] >> 5);
            int nbestRep = (trace[i][bestRep][bestPrev_c] >> 10);

            bestPrev_c = nbestPrev_c;
            bestRep = nbestRep;
            
            res += (c + 'a');
        }
        return res;
    }
};