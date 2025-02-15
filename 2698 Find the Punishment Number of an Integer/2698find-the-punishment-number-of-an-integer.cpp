#define MAXN 1005
#define MAX_DIGIT 8
int _dp[MAXN];
bool dp[MAX_DIGIT][MAXN];

auto init = []{
    int cur = 0;
    auto is_punishment = [&](int x) -> bool {
        string s = to_string(x*x);
        int n = s.size();
        dp[n][0] = true;
        for (int i = n - 1; i >= 0; i--)
            for (int j = 0; j <= x; j++) {
                dp[i][j] = false;
                if (s[i] == '0') {
                    dp[i][j] = dp[i + 1][j];
                    continue;
                }
                int cur = 0;
                for (int k = i; k < n; k++) {
                    cur = 10*cur + (s[k] - '0');
                    if (cur <= j) 
                        dp[i][j] = dp[i][j] | dp[k + 1][j - cur];
                    else 
                        break;
                }
            }
        return dp[0][x];
    };
    for (int i = 1; i < MAXN; i++) {
        if (is_punishment(i)) {
            cur += i*i;
        }
        _dp[i] = cur;
    }
    return 0;
}();
class Solution {
public:
    int punishmentNumber(int n) {
        return _dp[n];
    }
};