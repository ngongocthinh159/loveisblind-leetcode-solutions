#define ll long long
class Solution {
public:
    const int MOD = 1e9 + 7;
    ll getCost(int tar, ll diff_max, int cost1, int cost2, int n, int mn, int mx) {
        ll mn_inc = tar - mn;
        ll remain_inc = (diff_max - (mx - mn)) + 1LL*(tar - mx)*(n - 1);
        if (mn_inc > remain_inc) {
            return remain_inc*cost2 + (mn_inc - remain_inc)*cost1;
        }
        ll tot_inc = diff_max + n*(tar - mx);
        return tot_inc/2*cost2 + (tot_inc%2)*cost1;
    }
    int minCostToEqualizeArray(vector<int>& nums, int cost1, int cost2) {
        int n = nums.size();
        int mx = *max_element(nums.begin(), nums.end());
        int mn = *min_element(nums.begin(), nums.end());
        ll diff_max = 0;
        for (auto x : nums) {
            diff_max += (mx - x);
        }
        if (2*cost1 <= cost2) return diff_max*cost1 % MOD;

        ll ans_at_mx = getCost(mx, diff_max, cost1, cost2, n, mn, mx);
        int l = mx, r = mx + 1e6;
        while (r - l > 1) {
            int m = l + (r - l)/2;
            if (getCost(m, diff_max, cost1, cost2, n, mn, mx) < ans_at_mx)
                l = m;
            else
                r = m;
        }
        
        if (l == mx) return ans_at_mx % MOD;
        return getCost(l, diff_max, cost1, cost2, n, mn, mx) % MOD;
    }
};