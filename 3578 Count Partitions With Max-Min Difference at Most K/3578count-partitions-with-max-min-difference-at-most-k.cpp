#define ll long long
class Solution {
public:
    const int MOD = 1e9 + 7;
    void add(ll &x, ll y) {
        x += y;
        if (x >= MOD) x -= MOD;
    }
    void sub(ll &x, ll y) {
        x -= y;
        if (x < 0) x += MOD;
    }
    int countPartitions(vector<int>& nums, int k) {
        int n = nums.size();
        vector<ll> pref(n + 1);
        pref[0] = 1;
        vector<ll> dp(n);
        deque<int> mnq, mxq;
        for (int r = 0, l = 0; r < n; r++) {
            while (mnq.size() && nums[r] <= nums[mnq.back()]) mnq.pop_back();
            mnq.push_back(r);
            while (mxq.size() && nums[r] >= nums[mxq.front()]) mxq.pop_front();
            mxq.push_front(r);

            while (mnq.size() && !(l <= mnq.front() && mnq.front() <= r)) mnq.pop_front();
            while (mxq.size() && !(l <= mxq.back() && mxq.back() <= r)) mxq.pop_back();
            int mn = nums[mnq.front()];
            int mx = nums[mxq.back()];
            while (mx - mn > k) {
                l++;
                while (mnq.size() && !(l <= mnq.front() && mnq.front() <= r)) mnq.pop_front();
                while (mxq.size() && !(l <= mxq.back() && mxq.back() <= r)) mxq.pop_back();
                mn = nums[mnq.front()];
                mx = nums[mxq.back()];
            }

            add(dp[r], pref[r]);
            sub(dp[r], l - 1 >= 0 ? pref[l - 1] : 0);

            pref[r + 1] = pref[r];
            add(pref[r + 1], dp[r]);
        }
        return dp[n - 1];
    }
};