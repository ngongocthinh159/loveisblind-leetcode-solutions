#define MAX_DIGITS 5
unordered_map<int,long long> dp[MAX_DIGITS + 1][MAX_DIGITS + 1][2];
class Solution {
public:
    long long solve(string &upper) {
        int n = upper.size();
        const int MAX_DIF = (MAX_DIGITS + 1)/2 * 9 + 5;
        for (int len = n - (n&1); len >= 0; len -= 2)
            for (int i = n - 1; i >= n - len; i--) 
                for (int smaller = 0; smaller < 2; smaller++)
                    for (int dif = -MAX_DIF; dif <= MAX_DIF; dif++) {
                        int r = smaller ? 9 : upper[i] - '0';
                        long long res = 0;
                        for (int j = (i == n - len ? 1 : 0); j <= r; j++) {
                            int next_dif = dif + ((n - i) <= len/2 ? -j : j);
                            int next_smaller = smaller | (j < upper[i] - '0');
                            if (i + 1 == n)
                                res += next_dif == 0;
                            else if (abs(next_dif) > MAX_DIF)
                                res += 0;
                            else
                                res += dp[len][i + 1][next_smaller][next_dif];
                        }
                        dp[len][i][smaller][dif] = res;
                    }
        long long ans = 0;
        for (int len = n - (n&1); len >= 0; len -= 2)
            ans += dp[len][n - len][len < n][0];
        return ans;
    }
    int countSymmetricIntegers(int low, int high) {
        low--;
        string l_s = to_string(low);
        string h_s = to_string(high);
        return solve(h_s) - solve(l_s);
    }
};