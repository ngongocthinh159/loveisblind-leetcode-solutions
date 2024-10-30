const int INF = 1e9;
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        k++;
        // vector<vector<int>> dp(k + 1, vector<int>(n, INF));
        // dp[0][src] = 0;
        vector<int> cur(n, INF);
        vector<int> prev(n, INF);
        prev[src] = 0;
        int u,v,w;
        int ans = INF;
        for (int i = 0; i < k; i++) {
            fill(cur.begin(), cur.end(), INF);
            for (auto &edge : flights) {
                u = edge[0];
                v = edge[1];
                w = edge[2];
                // if (dp[i][u] != INF) {
                //     dp[i + 1][v] = min(dp[i + 1][v], dp[i][u] + w);
                // }
                // dp[i + 1][v] = min(dp[i + 1][v], dp[i][v]);
                if (prev[u] != INF) {
                    cur[v] = min(cur[v], prev[u] + w);
                }
                // cur[v] = min(cur[v], prev[v]);
            }
            prev = cur;
        }
        // if (dp[k][dst] == INF)return -1;
        // return dp[k][dst];
        if (cur[dst] == INF) return -1;
        return cur[dst];
    }
};