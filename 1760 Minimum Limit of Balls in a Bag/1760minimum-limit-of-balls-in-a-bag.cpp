#define ll long long
class Solution {
public:
    ll cnt(ll x, vector<int> &nums) {
        ll ans = 0;
        for (auto cur : nums) {
            if (cur <= x) continue;
            ans += (cur + x - 1)/x - 1;
        }
        return ans;
    }
    int minimumSize(vector<int>& nums, ll maxOperations) {
        ll l = 0, r = *max_element(nums.begin(), nums.end()) + 1;
        while (r - l > 1) {
            ll m = l + (r - l)/2;
            if (cnt(m, nums) <= maxOperations) {
                r = m;
            } else {
                l = m;
            }
        }
        return r;
    }
};