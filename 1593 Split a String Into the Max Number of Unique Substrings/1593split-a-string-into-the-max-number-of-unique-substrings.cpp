int dp[1 << 16];
const int MOD = 1e9 + 7;

class Solution {
public:
    int n;
    int dfs(int mask, int i, unordered_set<long long> &S, string &s) {
        if (i == n) {
            return 0;
        }
        if (dp[mask] != -1) return dp[mask];
        
        int res = 0;
        long long hash = 0;
        long long curPow = 1;
        for (int j = i; j < n; j++) {
            hash = (hash + (s[j] - 'a' + 1)*curPow%MOD) % MOD;

            if (!S.count(hash)) {
                S.insert(hash);
                res = max(res, 1 + dfs(mask | (1 << j), j + 1, S, s));
                S.erase(hash);
            }

            curPow = (curPow * 27) % MOD;
        }
        return dp[mask] = res;
    }
    int maxUniqueSplit(string s) {
        n = s.size();
        memset(dp, -1, sizeof(dp));
        unordered_set<long long> S;
        return dfs(0, 0, S, s);
    }
};