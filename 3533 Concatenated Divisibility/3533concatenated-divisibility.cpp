class Solution {
public:
    int n, tot_len = 0;
    vector<int> _10powmod;
    vector<vector<int>> dp;
    vector<int> len;
    vector<int> path, res;
    bool dfs(int mask, int mod, int chosen, int k, vector<int> &nums) {
        if (mask == ((1 << n) - 1)) {
            if (mod == 0 && !res.size()) {
                res = path;
            }
            return mod == 0;
        }
        if (res.size()) return true;
        if (dp[mask][mod] != -1) return dp[mask][mod];
        bool res = false;
        for (int i = 0; i < n; i++) if (!((mask >> i) & 1)) {
            int nMod = (mod + 1LL * _10powmod[tot_len - chosen - len[i]] * nums[i] % k) % k;
            path.push_back(nums[i]);
            if (dfs(mask | (1 << i), nMod, chosen + len[i], k, nums)) {
                res = true;
                break;
            }
            path.pop_back();
        }
        return dp[mask][mod] = res;
    }
    vector<int> concatenatedDivisibility(vector<int>& nums, int k) {
        n = nums.size();
        sort(nums.begin(), nums.end());
        len.resize(n);
        for (int i = 0; i < n; i++) len[i] = to_string(nums[i]).size(), tot_len += len[i];
        _10powmod.resize(tot_len);
        _10powmod[0] = 1 % k;
        for (int i = 1; i < tot_len; i++) _10powmod[i] = 1LL * _10powmod[i - 1] * 10 % k;
        dp.assign((1 << n), vector<int>(k, -1));
        dfs(0, 0, 0, k, nums);
        return res;
    }
};