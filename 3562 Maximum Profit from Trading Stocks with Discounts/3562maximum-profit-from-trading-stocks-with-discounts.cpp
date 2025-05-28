class Solution {
public:
    vector<vector<int>> g;
    vector<vector<vector<int>>> dp;
    int mx_budget;
    void dfs(int u, vector<int>& present, vector<int>& future) {
        for (auto v : g[u])
            dfs(v, present, future);
        
        int *cur0 = new int[mx_budget + 1]{};
        int *cur1 = new int[mx_budget + 1]{};
        for (auto v : g[u]) {
            int *ndp0 = new int[mx_budget + 1]{};
            int *ndp1 = new int[mx_budget + 1]{};
            for (int budget = 0; budget <= mx_budget; budget++) {
                for (int v_budget = 0; v_budget + budget <= mx_budget; v_budget++) {
                    ndp0[v_budget + budget] = max(ndp0[v_budget + budget], 
                                    cur0[budget] + dp[v][0][v_budget]);
                    ndp1[v_budget + budget] = max(ndp1[v_budget + budget],
                                    cur1[budget] + dp[v][1][v_budget]);
                }
            }
            swap(ndp0, cur0);
            swap(ndp1, cur1);
        }

        for (int budget = 0; budget <= mx_budget; budget++) {
            for (int parBuy = 0; parBuy < 2; parBuy++) {
                dp[u][parBuy][budget] = cur0[budget];

                int price = parBuy ? present[u]/2 : present[u];
                int profit = future[u] - price;
                if (budget >= price) {
                    dp[u][parBuy][budget] = max(dp[u][parBuy][budget], 
                        cur1[budget - price] + profit);
                }
            }
        }
    }
    int maxProfit(int n, vector<int>& present, vector<int>& future, vector<vector<int>>& hierarchy, int budget) {
        g.resize(n);
        mx_budget = budget;
        for (auto &e : hierarchy) {
            g[e[0] - 1].push_back(e[1] - 1);
        }
        dp.assign(n, vector<vector<int>>(2,
            vector<int>(budget + 1)));
        dfs(0, present, future);
        return dp[0][0][budget];
    }
};