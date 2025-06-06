#define ll long long
class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size();
        vector<ll> alter_sum(n);
        for (int i = 0; i < n; i++) {
            ll prev = i - 2 >= 0 ? alter_sum[i - 2] : 0;
            alter_sum[i] = nums[i] + prev;
        }
        ll cur = 0, prev = 0;
        int ans = 0;
        for (int i = n - 1; i >= 0; i--) {
            ll nxt1 = i - 1 >= 0 ? alter_sum[i - 1] : 0;
            ll nxt2 = i - 2 >= 0 ? alter_sum[i - 2] : 0;
            if (cur + nxt2 == prev + nxt1) 
                ans++;
            prev += nums[i];
            swap(prev, cur);
        }
        return ans;
    }
};