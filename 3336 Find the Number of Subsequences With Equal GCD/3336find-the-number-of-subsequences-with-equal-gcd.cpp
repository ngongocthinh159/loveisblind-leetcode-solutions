#define ll long long
class Solution {
public:
    const int MOD = 1e9 + 7;
    int mx = -1;
    ll dfs(int i, int gcd1, int gcd2, vector<int> &nums,
    vector<vector<vector<ll>>> &dp) {
        if (i == nums.size()) return gcd1 == gcd2 && gcd1 != mx + 1 && gcd2 != mx + 1;
        if (dp[i][gcd1][gcd2] != -1) return dp[i][gcd1][gcd2];
        
        ll res = 0;
        res += dfs(i + 1, gcd1 == mx + 1 ? nums[i] : __gcd(gcd1, nums[i]), gcd2, nums, dp);
        res %= MOD;
        res += dfs(i + 1, gcd1, gcd2 == mx + 1 ? nums[i] : __gcd(gcd2, nums[i]), nums, dp);
        res %= MOD;
        res += dfs(i + 1, gcd1, gcd2, nums, dp);
        res %= MOD;
        return dp[i][gcd1][gcd2] = res;
    }
    int subsequencePairCount(vector<int>& nums) {
        int n = nums.size();
        for (auto x : nums) mx = max(mx, x);
        vector<vector<vector<ll>>> dp(n,
            vector<vector<ll>>(mx + 2,
                vector<ll>(mx + 2, -1)));
        return dfs(0, mx + 1, mx + 1, nums, dp);
    }
};