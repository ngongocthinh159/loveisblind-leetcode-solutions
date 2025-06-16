#define ll long long
#define N 100005
ll dp[N][2][10];
class Solution {
public:
    const int MOD = 1e9 + 7;
    pair<string,int> divide(string &s, int x) {
        int remainder = 0;
        string quotient = "";
        for (auto c : s) {
            int cur = 10 * remainder + (c - '0');
            quotient += (cur / x) + '0';
            remainder = cur % x;
        }
        int idx = 0;
        while (idx < quotient.size() && quotient[idx] == '0') idx++;
        quotient = quotient.substr(idx);
        if (!quotient.size()) quotient = "0";
        return {quotient, remainder};
    }
    string convertBase(string &s, int toBase) {
        string res = "";
        vector<int> v;
        while (s != "0") {
            auto [quotient, remainder] = divide(s, toBase);
            v.push_back(remainder);
            s = quotient;
        }
        reverse(v.begin(), v.end());
        for (auto &x : v) res += to_string(x);
        return res;
    }
    void clearDp(int n) {
        for (int i = 0; i <= n; i++)
            for (int j = 0; j < 2; j++)
                for (int k = 0; k <= 9; k++) 
                    dp[i][j][k] = 0;
    }
    ll cnt(string &s, int b) {
        dp[0][0][0] = 1;
        int n = s.size();
        for (int i = 0; i < n; i++)
            for (int smaller = 0; smaller < 2; smaller++)
                for (int prevD = 0; prevD < b; prevD++) if (dp[i][smaller][prevD]) {
                    int upper = smaller ? b - 1 : s[i] - '0';
                    int lower = prevD;
                    for (int j = lower; j <= upper; j++) {
                        int nsmaller = smaller | (j < (s[i] - '0'));
                        dp[i + 1][nsmaller][j] += dp[i][smaller][prevD];
                        if (dp[i + 1][nsmaller][j] >= MOD) 
                            dp[i + 1][nsmaller][j] -= MOD;
                    }
                }
        ll ans = 0;
        for (int smaller = 0; smaller < 2; smaller++) 
            for (int prevD = 0; prevD < b; prevD++) {
                ans += dp[n][smaller][prevD];
                if (ans >= MOD) ans -= MOD;
            }
        return ans;
    }
    int countNumbers(string l, string r, int b) {
        int i = l.size() - 1;
        while (i >= 0 && l[i] == '0') {
            l[i] = '9';
            i--;
        }
        l[i] -= 1;
        i = 0;
        while (i < l.size() && l[i] == '0') i++;
        l = l.substr(i);

        string convertedR = convertBase(r, b);
        clearDp(convertedR.size());
        ll res1 = cnt(convertedR, b);

        string convertedL = convertBase(l, b);
        clearDp(convertedL.size());
        ll res2 = cnt(convertedL, b);
        ll res = (res1 - res2) % MOD;
        if (res < 0) res += MOD;
        return res;
    }
};