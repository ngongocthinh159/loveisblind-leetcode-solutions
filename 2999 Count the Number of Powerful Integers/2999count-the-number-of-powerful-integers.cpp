#define ll long long
ll dp[2], ndp[2];
class Solution {
public:
    ll get_ans(string &upper, int limit, string& sur) {
        if (upper.size() < sur.size()) return 0;
        int n = upper.size(); 
        dp[0] = dp[1] = 1;
        for (int i = n - 1; i >= 0; i--) {
            ndp[0] = ndp[1] = 0;
            for (int smaller = 0; smaller < 2; smaller++) {
                int r = min(smaller ? 9 : upper[i] - '0', limit);
                if (upper.size() - i <= sur.size()) {
                    int j = sur[i - (upper.size() - sur.size())] - '0';
                    if (r >= j)
                        ndp[smaller] += dp[smaller | (j < upper[i] - '0')];
                } else {
                    if (smaller || r < upper[i] - '0')
                        ndp[smaller] += (r + 1) * dp[1];
                    else {
                        if (r == upper[i] - '0') {
                            ndp[smaller] += dp[0];
                            ndp[smaller] += r * dp[1];
                        } else {
                            ndp[smaller] += (r + 1) * dp[1];
                        }
                    }
                }
            }
            swap(dp, ndp);
        }
        return dp[0];
    }
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        --start;
        string s_start = to_string(start);
        string s_finish = to_string(finish);
        return get_ans(s_finish, limit, s) - get_ans(s_start, limit, s);
    }
};