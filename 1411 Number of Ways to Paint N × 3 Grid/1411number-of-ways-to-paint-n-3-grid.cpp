#define ll long long
class Solution {
public:
    const int MOD = 1e9 + 7;
    bool check(int i, int j, unordered_map<int,string> &M) {
        for (int k = 0; k < 3; k++) if (M[i][k] == M[j][k]) return false;
        return true;
    }
    int numOfWays(int n) {
        unordered_map<int,string> M;
        M[0] = "RGB";
        M[1] = "RBG";
        M[2] = "GRB";
        M[3] = "GBR";
        M[4] = "BRG";
        M[5] = "BGR";
        M[6] = "BRB";
        M[7] = "RBR";
        M[8] = "BGB";
        M[9] = "GBG";
        M[10] = "RGR";
        M[11] = "GRG";
        vector<vector<ll>> dp(n, vector<ll>(12));
        vector<vector<int>> g(12);
        for (int i = 0; i < 12; i++)
            for (int j = 0; j < 12; j++) if (check(i, j, M)) g[i].push_back(j);
        for (int j = 0; j < 12; j++) dp[0][j] = 1;
        for (int i = 1; i < n; i++)
            for (int j = 0; j < 12; j++)
                for (auto k : g[j]) dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
        ll ans = 0;
        for (int j = 0; j < 12; j++) ans = (ans + dp[n - 1][j]) % MOD;
        return ans;
    }
};