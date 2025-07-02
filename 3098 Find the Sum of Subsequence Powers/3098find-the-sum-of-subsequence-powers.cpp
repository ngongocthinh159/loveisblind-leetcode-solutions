#define ll long long
ll dp[55][55][55];
const int MOD = 1e9 + 7;
class Solution {
public:
    void add(ll &x, ll y) {
        x += y;
        if (x >= MOD) x -= MOD;
    }
    ll cal(int D, vector<int> &nums, int k) {
        int n = nums.size();
        for (int i = 0; i < n; i++)
            for (int j = 0; j <= i + 1; j++)
                for (int len = 0; len <= k; len++) dp[i][j][len] = 0;
        for (int i = 0; i < n; i++) {
            add(dp[i][i][1], 1);
            if (i + 1 < n) {
                for (int j = 0; j <= i; j++) {
                    for (int len = 0; len <=  min(i + 1, k); len++) if (dp[i][j][len]) {
                        add(dp[i + 1][j][len], dp[i][j][len]);
                        if (nums[i + 1] - nums[j] >= D)
                            add(dp[i + 1][i + 1][len + 1], dp[i][j][len]);
                    }   
                }
            }
        }

        ll ans = 0;
        for (int j = 0; j < n; j++)
            add(ans, dp[n - 1][j][k]);
        return ans;
    }
    int sumOfPowers(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dif;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++) dif.push_back(abs(nums[j] - nums[i]));
        sort(dif.begin(), dif.end());
        dif.erase(unique(dif.begin(), dif.end()), dif.end());
        ll prev = 0;
        ll ans = 0;
        for (int i = (int) dif.size() - 1; i >= 0; i--) {
            int x = dif[i];
            ll cur = cal(x, nums, k);

            ll cnt = cur - prev;
            if (cnt < 0) cnt += MOD;
            add(ans, x * cnt % MOD);

            prev = cur;
        }
        return ans;
    }
};