#define N 100005
#define ll long long
ll _2pow[N];
const int MOD = 1e9 + 7;
auto init = []{
    _2pow[0] = 1;
    for (int i = 1; i < N; i++) _2pow[i] = _2pow[i - 1] * 2 % MOD;
    return 0;
}();
class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        long long ans = 0;
        for (int r = 0, l = 0; r < n; r++) {
            if (nums[r] + nums[r] <= target) {
                l = r;
                ans += _2pow[l];
                if (ans >= MOD) ans -= MOD;
            } else {
                while (l >= 0 && nums[l] + nums[r] > target) l--;

                if (l >= 0) {
                    ll cur = _2pow[l + 1] - 1;
                    if (cur < 0) cur += MOD;
                    int len = r - 1 - (l + 1) + 1;
                    if (len >= 0) cur = cur * _2pow[len] % MOD;
                    ans = ans + cur;
                    if (ans >= MOD) ans -= MOD;
                }
            }
        }
        return static_cast<int> (ans);
    }
};