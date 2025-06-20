class Solution {
public:
    int maxDistance(string s, int k) {
        int idx[26]{};
        idx['N' - 'A'] = 0;
        idx['S' - 'A'] = 1;
        idx['E' - 'A'] = 2;
        idx['W' - 'A'] = 3;
        int ans = 0;
        int n = s.size();
        int cnt[4]{};
        for (int i = 0; i < n; i++) {
            cnt[idx[s[i] - 'A']]++;
            int mn1 = cnt[0] <= cnt[1] ? 0 : 1;
            int mn2 = cnt[2] <= cnt[3] ? 2 : 3;
            int can1 = min(cnt[mn1], k);
            int can2 = min(cnt[mn2], k - can1);
            int can3 = min(n - i - 1, k - can1 - can2);
            ans = max(ans, 2*(can1 + can2) + can3 +
                        cnt[mn1 ^ 1] - cnt[mn1] + cnt[mn2 ^ 2 ^ 3] - cnt[mn2]);
        }
        return ans;
    }
};