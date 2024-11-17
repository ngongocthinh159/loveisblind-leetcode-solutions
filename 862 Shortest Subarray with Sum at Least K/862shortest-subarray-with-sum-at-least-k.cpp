#define ll long long
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<ll> pre(n + 1);
        for (int i = 1; i <= n; i++) pre[i] = nums[i - 1] + pre[i - 1];
        deque<pair<ll,int>> q;
        q.push_back({0, -1});
        int ans = INT_MAX;
        for (int r = 0; r < nums.size(); r++) {
            ll target = pre[r + 1] - k;
            while (q.size() && (pre[r] <= q.back().first)) q.pop_back();
            q.push_back({pre[r], r});
            while (q.size() && (!(r - ans + 1 <= q.front().second && q.front().second <= r) || q.front().first <= target)) {
                if (!(r - ans + 1 <= q.front().second && q.front().second <= r)) {
                    q.pop_front();
                } else {
                    ans = min(ans, r - q.front().second + 1);
                    q.pop_front();
                }
            }
        }
        return (ans == INT_MAX ? -1 : ans);
    }
};