class Solution {
public:
    vector<pair<int,int>> in;
    vector<int> ans; 
    vector<vector<int>> g;
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        in = vector<pair<int,int>>(n);
        ans = vector<int>(n);
        g = vector<vector<int>>(n);
        for (auto &e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        dfs1(0, -1);
        dfs2(0, -1, {0,1});
        return ans;
    }
    void dfs1(int u, int parent) {
        if (g[u].size() == 1 && g[u][0] == parent) {
            in[u] = {0, 1};
            return;
        }

        int total_dist = 0;
        int total_nodes = 0;
        for (auto &v : g[u]) {
            if (v != parent) {
                dfs1(v, u);
                total_dist += in[v].first + (in[v].second - 1) + 1;
                total_nodes += in[v].second;
            }
        }
        total_nodes += 1;
        in[u] = {total_dist, total_nodes};
    }
    void dfs2(int u, int parent, pair<int,int> out_u) {
        ans[u] = in[u].first + out_u.first;
        for (auto &v : g[u]) {
            if (v != parent) {
                int fi = in[u].first - (in[v].first + (in[v].second - 1) + 1) + out_u.first;
                int se = in[u].second - in[v].second + out_u.second - 1;
                fi = fi + (se - 1) + 1;
                se += 1;
                pair<int,int> out_v = {fi, se};
                dfs2(v, u, out_v);
            }
        }
    }
};
