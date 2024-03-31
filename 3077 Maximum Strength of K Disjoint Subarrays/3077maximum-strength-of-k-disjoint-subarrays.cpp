#define ll long long
class Solution {
public:
    ll dead = LONG_MIN + 1;
    vector<vector<vector<ll>>> dp;
    long long maximumStrength(vector<int>& nums, int k) {
        int n = nums.size();
        dp = vector<vector<vector<ll>>>(2, vector<vector<ll>>(n, vector<ll>(k, LONG_MIN)));
        return dfs(0, 0, 0, nums, k);
    }
    // state == 0: no element current subarray
    // state == 1: has at least one current subarray
    ll dfs(int state, int i, int j, vector<int> &nums, int k) {
        if (j >= k) return 0;
        if (i >= nums.size()) {
            if (j == k - 1 && state) return 0;
            else return dead;
        }
        if (dp[state][i][j] != LONG_MIN) return dp[state][i][j];

        ll a = k - j;
        ll res = dead;

        if (state == 0) {
            // skip
            // not end
            ll tmp1 = dfs(0, i + 1, j, nums, k);
            if (tmp1 != dead) res = max(res, tmp1);

            // chose
            // not end
            ll tmp2 = dfs(1, i + 1, j, nums, k);
            if (tmp2 != dead) res = max(res, a*nums[i]*(a&1 ? 1 : -1) + tmp2);
            
            // end
            ll tmp3 = dfs(0, i + 1, j + 1, nums, k);
            if (tmp3 != dead) res = max(res, a*nums[i]*(a&1 ? 1 : -1) + tmp3);
        } else {
            // skip
            // end
            ll tmp1 = dfs(0, i, j + 1, nums, k);
            if (tmp1 != dead) res = max(res, tmp1);

            // choose
            // not end
            ll tmp2 = dfs(1, i + 1, j, nums, k);
            if (tmp2 != dead) res = max(res, a*nums[i]*(a&1 ? 1 : -1) + tmp2);

            // end
            ll tmp3 = dfs(0, i + 1, j + 1, nums, k);
            if (tmp3 != dead) res = max(res, a*nums[i]*(a&1 ? 1 : -1) + tmp3);
        }

        return dp[state][i][j] = res;
    }
};