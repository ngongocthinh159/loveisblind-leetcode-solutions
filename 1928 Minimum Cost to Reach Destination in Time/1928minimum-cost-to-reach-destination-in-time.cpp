#define ll long long
class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n = 0;
        for (auto &e : edges) {
            n = max(n, max(e[0], e[1]));
        }
        n++;
        vector<vector<pair<int,int>>> g(n);
        for (auto &e : edges) {
            g[e[0]].push_back({e[1], e[2]});
            g[e[1]].push_back({e[0], e[2]});
        }
        const ll LINF = 1e18;
        vector<vector<ll>> dp(n,
            vector<ll>(maxTime + 1, LINF));
        dp[0][0] = passingFees[0];
        set<pair<ll, pair<int,int>>> S;
        S.insert({passingFees[0], {0, 0}});
        while (S.size()) {
            auto p = *S.begin();
            S.erase(S.begin());
            ll cost_u = p.first;
            int u = p.second.first;
            int time_u = p.second.second;
            for (auto [v, time_uv] : g[u]) {
                int time_v = time_u + time_uv;
                if (time_v <= maxTime && dp[v][time_v] > cost_u + passingFees[v]) {
                    S.erase({dp[v][time_v], {v, time_v}});
                    dp[v][time_v] = cost_u + passingFees[v];
                    S.insert({dp[v][time_v], {v, time_v}});
                }
            }
        }
        ll ans = LINF;
        for (int i = 0; i <= maxTime; i++) ans = min(ans, dp[n - 1][i]);
        if (ans == LINF) return -1;
        return ans;
    }
};