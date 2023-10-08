class Solution {
public:
    int mod = 1e9 + 7;
    int n;
    int m;
    int k;
    vector<vector<vector<int>>> dp;
    int addMod(int a, int b) {
        return (a%mod + b%mod)%mod;
    }
    int mulMod(int a, int b) {
        return (a%mod + b%mod)%mod;
    }
    int numOfArrays(int n, int m, int k) {
        this->n = n;
        this->m = m;
        this->k = k;

        dp = vector(n, vector(m + 1, vector(k + 1, -1)));
        return solve(0, 0, k);
    }

    int solve(int i, int maxTilNow, int remain) {
        if (i == n) {
            if (remain == 0) return 1;
            else return 0;
        }
        if (remain < 0) return 0;

        if (dp[i][maxTilNow][remain] != -1) return dp[i][maxTilNow][remain];

        int ans = 0;
        for (int j = 1; j <= maxTilNow; j++) {
            ans = addMod(ans, solve(i + 1, maxTilNow, remain));
        }

        for (int j = maxTilNow + 1; j <= m; j++) {
            ans = addMod(ans, solve(i + 1, j, remain - 1));
        }

        return dp[i][maxTilNow][remain] = ans;
    }
};