class Solution {
public:
    vector<int> par, time_bob;
    vector<vector<int>> g;
    void dfs(int u, int _par) {
        for (auto v : g[u]) if (v != _par) {
            par[v] = u;
            dfs(v, u);
        }
    }
    void dfs2(int u, int time) {
        time_bob[u] = time;
        if (par[u] != -1) dfs2(par[u], time + 1);
    }
    int dfs3(int u, int _par, int time, vector<int>& amount) {
        int res = 0, mx = INT_MIN;
        if (time == time_bob[u]) 
            res = amount[u]/2;
        else if (time < time_bob[u]) 
            res = amount[u];
        for (auto v : g[u]) if (v != _par) {
            mx = max(mx, dfs3(v, u, time + 1, amount));
        }
        return res + (mx != INT_MIN ? mx : 0);
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = edges.size() + 1;
        g.resize(n);
        par.resize(n);
        time_bob.assign(n, INT_MAX);
        for (auto &e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        dfs(0, -1);
        par[0] = -1;
        dfs2(bob, 0);
        return dfs3(0, -1, 0, amount);
    }
};