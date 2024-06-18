class Solution {
public:
    vector<pair<int,int>> v;
    long long maximumTotalDamage(vector<int>& power) {
        sort(power.begin(), power.end());
        int start;
        for (int i = 0; i < power.size();) {
            start = power[i];
            int cnt = 1;
            while (i + 1 < power.size() && power[i + 1] == start) {
                i++;
                cnt++;
            }
            v.push_back({start, cnt});
            i++;
        }
        vector<long long> dp(v.size() + 1);
        dp[0] = 1LL*v[0].first * v[0].second;
        int prev_idx;
        for (int i = 1; i < v.size(); i++) {
            prev_idx = -1;
            dp[i] = dp[i - 1];
            
            if (i - 1 >= 0 && v[i].first - v[i - 1].first > 2) prev_idx = i - 1;
            else if (i - 2 >= 0 && v[i].first - v[i - 2].first > 2) prev_idx = i - 2;
            else if (i - 3 >= 0) prev_idx = i - 3;
            
            if (prev_idx >= 0) dp[i] = max(dp[i], 1LL*v[i].first*v[i].second + dp[prev_idx]);
            else dp[i] = max(dp[i], 1LL*v[i].first*v[i].second);
        }
        return dp[v.size() - 1];
    }
};