class Solution {
public:
    const int mod = 1e9 + 7;
    int valueAfterKSeconds(int n, int k) {
        vector<int> prev(n, 1);
        for (int i = 1; i <= k; i++) {
            vector<int> cur(n, 0);
            cur[0] = 1;
            for (int j = 1; j < n; j++) {
                cur[j] = (cur[j - 1] + prev[j]) % mod;
            }
            prev = cur;
        }
        return prev[n - 1];
    }
};