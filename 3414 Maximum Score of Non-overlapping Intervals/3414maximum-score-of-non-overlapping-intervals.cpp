#define ll long long
class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> order(n);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int i, int j) {
            return intervals[i][0] < intervals[j][0];
        });
        vector<vector<pair<ll,pair<int,vector<int>>>>> dp(n + 1, 
            vector<pair<ll,pair<int,vector<int>>>>(5, {0, {INT_MAX, {}}}));
        for (int i = n - 1; i >= 0; i--)
            for (int j = 1; j <= 4; j++) {
                // chosen
                ll chosen_point = LLONG_MIN;
                int chosen_min_idx;
                vector<int> chosen_idxs;
                if (j > 0) {
                    int l = i, r = n;
                    while (r - l > 1) {
                        int m = l + (r - l)/2;
                        if (intervals[order[m]][0] > intervals[order[i]][1])
                            r = m;
                        else
                            l = m;
                    }
                    chosen_point = intervals[order[i]][2] + dp[r][j - 1].first;
                    chosen_min_idx = min(order[i], dp[r][j - 1].second.first);
                    chosen_idxs = dp[r][j - 1].second.second;
                    chosen_idxs.push_back(order[i]);
                }

                ll not_chosen_point = dp[i + 1][j].first;
                int not_chosen_min_idx = dp[i + 1][j].second.first;
                vector<int> not_chosen_idxs = dp[i + 1][j].second.second;
                if (chosen_point > not_chosen_point) {
                    dp[i][j] = {chosen_point, {chosen_min_idx, chosen_idxs}};
                } else if (chosen_point < not_chosen_point) {
                    dp[i][j] = {not_chosen_point, {not_chosen_min_idx, not_chosen_idxs}};
                } else {
                    sort(chosen_idxs.begin(), chosen_idxs.end());
                    sort(not_chosen_idxs.begin(), not_chosen_idxs.end());
                    // if (chosen_idxs <= not_chosen_idxs) {
                    //     dp[i][j] = {chosen_point, {chosen_min_idx, chosen_idxs}};
                    // } else {
                    //     dp[i][j] = {not_chosen_point, {not_chosen_min_idx, not_chosen_idxs}};
                    // }
                    if (not_chosen_idxs <= chosen_idxs) {
                        dp[i][j] = {not_chosen_point, {not_chosen_min_idx, not_chosen_idxs}};
                    } else {
                        dp[i][j] = {chosen_point, {chosen_min_idx, chosen_idxs}};
                    }
                }
            }
        vector<int> ans = dp[0][4].second.second;
        sort(ans.begin(), ans.end());
        return ans;
    }
};