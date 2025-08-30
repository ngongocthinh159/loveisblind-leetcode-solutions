class Solution {
public:
    int find_wall(int s, int e, vector<int>& w) {
        auto it = lower_bound(w.begin(), w.end(), s);
        if (it != w.end()) {
            auto it2 = upper_bound(w.begin(), w.end(), e);
            return it2 - it;
        }
        return 0;
    }
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int n = robots.size();
        vector<vector<int>> dp(n, vector<int>(2));
        vector<int> order(n);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int i, int j) {
            return robots[i] < robots[j];
        });
        vector<int> nr(n), nd(n);
        for (int i = 0; i < n; i++) {
            nr[i] = robots[order[i]];
            nd[i] = distance[order[i]];
        }
        swap(robots,nr);
        swap(distance,nd);
        sort(walls.begin(), walls.end());
        for (int i = 0; i < n; i++) {
            int s1, e1;
            for (int j = 0; j < 2; j++) {
                if (j == 0) {
                    e1 = robots[i];
                    s1 = e1 - distance[i];
                } else {
                    s1 = robots[i];
                    e1 = s1 + distance[i];
                }
                if (i + 1 < n)
                    e1 = min(e1, robots[i + 1]);
                if (i - 1 >= 0) {
                    int s2, e2;
                    for (int k = 0; k < 2; k++) {
                        if (k == 0) {
                            e2 = robots[i - 1];
                            s2 = e2 - distance[i - 1];
                        } else {
                            s2 = robots[i - 1];
                            e2 = s2 + distance[i - 1];
                        }
                        e2 = min(e2, robots[i]);
                        s1 = max(s1, robots[i - 1] + 1);
                        if (e2 < e1) {
                            int s = max(s1, e2 + 1);
                            int e = e1;
                            auto c = find_wall(s, e, walls);
                            dp[i][j] = max(dp[i][j], dp[i - 1][k] + c);
                        }
                    }
                } else {
                    auto c = find_wall(s1, e1, walls);
                    dp[i][j] = max(dp[i][j], c);
                }
            }
        }
        return max(dp[n - 1][0], dp[n - 1][1]);
    }
};