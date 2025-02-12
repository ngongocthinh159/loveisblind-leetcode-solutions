class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n + 1, vector<int>(n + 1, INT_MAX));
        for (int i = 1; i <= n; i++) dist[i][i] = 0;
        for (auto &e : edges) {
            dist[e[0] + 1][e[1] + 1] = min(dist[e[0] + 1][e[1] + 1], e[2]);
            dist[e[1] + 1][e[0] + 1] = min(dist[e[1] + 1][e[0] + 1], e[2]);
        }
        for (int k = 0; k <= n; k++)
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= n; j++) if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
        int mx_cnt = INT_MAX, ans = n;
        for (int i = 1; i <= n; i++) {
            int cnt = 0;
            for (int j = 1; j <= n; j++) if (i != j) {
                if (dist[i][j] <= distanceThreshold) cnt++;
            }
            if (mx_cnt >= cnt) {
                mx_cnt = cnt;
                ans = i;
            }
        }
        return ans - 1;
    }
};