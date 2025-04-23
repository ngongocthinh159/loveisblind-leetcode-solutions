class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        const int IINF = 1e9 + 5;
        vector<long long> dp(n + 1, -IINF);
        dp[n] = 0;
        for (int i = n - 1; i >= 0; i--) {
            long sum = 0;
            for (int j = i; j <= i + 3 - 1 && j < n; j++) {
                sum += stoneValue[j];
                dp[i] = max(dp[i], sum - dp[j + 1]);
            }
        } 
        if (dp[0] == 0) return "Tie";
        else if (dp[0] > 0) return "Alice";
        return "Bob";
    }
};