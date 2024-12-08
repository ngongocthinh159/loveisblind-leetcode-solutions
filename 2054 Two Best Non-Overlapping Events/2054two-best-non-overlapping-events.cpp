class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        int n = events.size();
        vector<int> mx(n);
        for (int i = n - 1; i >= 0; i--) {
            mx[i] = i == n - 1 ? events[i][2] : max(events[i][2], mx[i + 1]);
        }
        int start, end, val;
        int ans = INT_MIN;
        for (int i = n - 1; i >= 0; i--) {
            start = events[i][0];
            end = events[i][1];
            val = events[i][2];
            int l = -1, r = n;
            while (r - l > 1) {
                int m = l + (r - l)/2;
                if (events[m][0] > end) {
                    r = m;
                } else {
                    l = m;
                }
            }
            if (r != n) {
                ans = max(ans, val + mx[r]);
            } else {
                ans = max(ans, val);
            }
        }
        return ans;
    }
};