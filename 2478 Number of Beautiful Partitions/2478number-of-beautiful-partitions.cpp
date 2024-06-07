class Solution {
public:
    const int MOD = 1e9 + 7;
    int beautifulPartitions(string s, int k, int minLength) {
        vector<bool> isPrime(10, false);
        vector<int> v;
        isPrime[2] = isPrime[3] = isPrime[5] = isPrime[7] = true;
        int n = s.size();
        if (n < 2) return 0;
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        if (!isPrime[s[0] - '0'] || isPrime[s[n - 1] - '0']) return 0;
        s += '2';
        for (int i = 0; i < n; i++) {
            if (!isPrime[s[i] - '0'] && isPrime[s[i + 1] - '0']) v.push_back(i);
        }
        vector<vector<int>> dp2(v.size(), vector<int>(k + 1, -1));
        dp[n][0] = 1;
        for (int i = n - 1; i >= 0; i--) {
            if (isPrime[s[i] - '0']) {
                for (int j = 1; j <= k; j++) {
                    int res = 0;
                    int tar = i + minLength - 1;
                    auto it = lower_bound(v.begin(), v.end(), tar);
                    if (it != v.end()) {
                        int idx = it - v.begin();
                        for (int p = idx; p < v.size(); p++) {
                            if (dp2[p][j - 1] != -1) {
                                res = (res + dp2[p][j - 1]) % MOD;
                                break;
                            } else {
                                res = (res + dp[v[p] + 1][j - 1]) % MOD;
                            }
                        }
                        dp2[idx][j - 1] = res;
                    } 
                    dp[i][j] = res;
                }
            }
        }
        
        return dp[0][k];
    }
};