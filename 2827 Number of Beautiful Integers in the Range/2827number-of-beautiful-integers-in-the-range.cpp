class Solution {
public:
    int lower, upper, k;
    vector<vector<int>> digit;
    int dp[11][11][11][2][21];
    int dfs(int i, int odd, int even, bool prev_smaller_upper, int remain, vector<int> &digits) {
        if (i == digits.size()) {
            return (odd == even && remain == 0);
        }
        if (dp[i][odd][even][prev_smaller_upper][remain] != -1) {
            return dp[i][odd][even][prev_smaller_upper][remain];
        }

        int h, l;
        h = prev_smaller_upper ? 9 : digits[i];
        l = i != digits.size() - 1 ? 0 : (odd == 0 && even == 0 ? 1 : 0);
        int newRemain;
        int newEven;
        int res = 0;
        for (int dg = l; dg <= h; dg++) {
            newRemain = dg*pow(10, (digits.size() - i - 1));
            newRemain %= k;
            newRemain = (newRemain + remain) % k;

            newEven = even;
            if ((dg != 0 && !(dg & 1)) || (dg == 0 && (odd > 0 || even > 0))) newEven++;

            res
                += dfs(i + 1, odd + (dg & 1 ? 1 : 0), newEven, prev_smaller_upper | (dg < digits[i]), newRemain, digits);
        }
        return dp[i][odd][even][prev_smaller_upper][remain] = res;
    }
    int numberOfBeautifulIntegers(int low, int high, int _k) {
        memset(dp,-1,sizeof(dp));

        lower = low, upper = high;
        k = _k;
        string high_s = to_string(high);
        low--;
        string low_s = to_string(low);
        digit.resize(2);
        digit[1].resize(high_s.size());
        digit[0].resize(low_s.size());
        for (int i = 0; i < high_s.size(); i++) {
            digit[1][i] = high_s[i] - '0';
        }
        for (int i = 0; i < low_s.size(); i++) {
            digit[0][i] = low_s[i] - '0';
        }
        int tmp = dfs(0, 0, 0, false, 0, digit[1]);
        memset(dp,-1,sizeof(dp));
        int tmp2 = dfs(0, 0, 0, false, 0, digit[0]);
        return tmp - tmp2;
    }
};