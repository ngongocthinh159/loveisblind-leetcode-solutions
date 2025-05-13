#define ll long long
#define T 100005
const int MOD = 1e9 + 7;
int dp[26][T];
auto init = []{
    for (int c = 0; c < 26; c++) dp[c][0] = 1;
    for (int t = 1; t < T; t++)
        for (int c = 0; c < 26; c++) {
            if (c < 25) 
                dp[c][t] = dp[c + 1][t - 1];
            else
                dp[c][t] = (dp[0][t - 1] + dp[1][t - 1]) % MOD;
        }
    return 0;
}();
class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        ll ans = 0;
        for (auto c : s) {
            ans += dp[c - 'a'][t];
            if (ans >= MOD) ans -= MOD;
        }
        return ans;
    }
};