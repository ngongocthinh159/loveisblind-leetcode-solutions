#define ll long long
const int MOD = 1e9 + 7;
class Solution {
public:
    int countSpecialSubsequences(vector<int>& nums) {
        vector<ll> c(3);
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                c[0] = c[0] * 2 % MOD;
                c[0] = (c[0] + 1) % MOD;
            }
            if (nums[i] == 1) {
                c[1] = c[1] * 2 % MOD;
                c[1] = (c[0] + c[1]) % MOD;
            }
            if (nums[i] == 2) {
                c[2] = c[2] * 2 % MOD;
                c[2] = (c[1] + c[2]) % MOD;
            }
        }
        return c[2];
    }
};