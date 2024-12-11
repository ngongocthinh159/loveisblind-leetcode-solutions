#define ll long long
class Solution {
public:
    int sumOfGoodSubsequences(vector<int>& nums) {
        int n = nums.size();
        const int MOD = 1e9 + 7;
        unordered_map<int,pair<ll,ll>> M;
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            ll sum = 0;
            ll cnt = 0;
            if (M.count(nums[i] - 1)) {
                sum += (M[nums[i] - 1].first + M[nums[i] - 1].second * nums[i] % MOD) % MOD;
                sum %= MOD;
                cnt += M[nums[i] - 1].second;
                cnt %= MOD;
            }
            if (M.count(nums[i] + 1)) {
                sum += (M[nums[i] + 1].first + M[nums[i] + 1].second * nums[i] % MOD) % MOD;
                sum %= MOD;
                cnt += M[nums[i] + 1].second;
                cnt %= MOD;
            }
            sum += nums[i];
            sum %= MOD;
            cnt++;
            cnt %= MOD;
            ans = (ans + sum) % MOD;
            if (M.count(nums[i])) {
                M[nums[i]] = {(M[nums[i]].first + sum) % MOD, M[nums[i]].second + cnt};
            } else M[nums[i]] = {sum, cnt};
        }
        return ans;
    }
};