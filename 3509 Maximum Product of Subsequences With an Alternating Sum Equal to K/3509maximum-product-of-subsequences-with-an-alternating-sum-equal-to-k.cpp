class Solution {
public:
    const int IINF = 1e9;
    int maxProduct(vector<int>& nums, int k, int limit) {
        int n = nums.size();
        int sum = 0;
        for (auto x : nums) sum += x;
        const int OFF = sum + 25;
        if (abs(k) > sum) return -1;
        vector<vector<vector<unordered_set<int>>>> dp(n, 
            vector<vector<unordered_set<int>>>(OFF + 2 * sum + 1, 
                vector<unordered_set<int>>(2)));
        for (int i = 0; i < n; i++) {
            // start new sequence
            dp[i][nums[i] + OFF][0].insert(nums[i]);

            if (i + 1 == n) break;

            for (int cur_sum = -sum; cur_sum <= sum; cur_sum++) {
                for (int par = 0; par < 2; par++) {
                    for (auto prod : dp[i][cur_sum + OFF][par]) {
                        // not choose
                        dp[i + 1][cur_sum + OFF][par].insert(prod);

                        // choose
                        int npar = par^1;
                        int nsum = cur_sum + OFF + nums[i + 1] * (npar == 0 ? 1 : -1);
                        int nprod = min(1LL * prod * nums[i + 1], 1LL * limit + 1);
                        dp[i + 1][nsum][npar].insert(nprod);
                    }
                }
            }
        }
        // for (auto x : dp[1][-1 + OFF][1]) cout << x << ' '; 
        if (dp[n - 1][k + OFF][0].empty() && dp[n - 1][k + OFF][1].empty())
            return -1;
        int ans = -IINF;
        for (int par = 0; par < 2; par++) {
            for (auto prod : dp[n - 1][k + OFF][par]) if (prod != limit + 1)
                ans = max(ans, prod);
        }
        return ans == -IINF ? -1 : ans;
    }
};  