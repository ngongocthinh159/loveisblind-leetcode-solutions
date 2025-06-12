#define ll long long
class Solution {
public:
    const int MOD = 1e9 + 7;
    void add(ll &x, ll y) {
        x += y;
        if (x >= MOD) x -= MOD;
    }
    int countKReducibleNumbers(string s, int k) {
        int n = s.size();
        vector<vector<vector<ll>>> dp(n + 1, vector<vector<ll>>(n + 1, 
            vector<ll>(2)));
        dp[0][0][0] = 1;
        for (int i = 0; i < n; i++) {
            int c = s[i] - '0';
            for (int j = 0; j <= n; j++) 
                for (int smaller = 0; smaller < 2; smaller++) if (dp[i][j][smaller]) {
                    int upper = smaller ? 1 : c;
                    for (int k = 0; k <= upper; k++) {
                        add(dp[i + 1][j + k][smaller | (k < c)], dp[i][j][smaller]);
                    }
                }
        }
            
        // cout << dp[n][1][1] << "\n";
        vector<int> dp2(n + 1);
        dp2[1] = 0;
        for (int i = 2; i <= n; i++) {
            dp2[i] = 1 + dp2[__builtin_popcount(i)];
        }
        ll ans = 0;
        for (int i = 1; i <= n; i++) {
            if (dp2[i] + 1 <= k)
                add(ans, dp[n][i][1]);
        }
        return ans;
    }
};