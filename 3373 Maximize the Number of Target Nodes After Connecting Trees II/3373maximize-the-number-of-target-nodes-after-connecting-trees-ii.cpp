class Solution {
public:
    void dfs(int u, int p, vector<int> &col, int *cnt, int cur_color, vector<vector<int>> &g) {
        col[u] = cur_color;
        cnt[cur_color]++;
        for (auto v : g[u]) if (v != p) {
            dfs(v, u, col, cnt, cur_color ^ 1, g);
        }
    }
    void color(vector<vector<int>>& edges, vector<int> &col, int *cnt) {
        int n = edges.size() + 1;
        vector<vector<int>> g(n);
        for (auto &e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        dfs(0, -1, col, cnt, 0, g);
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;
        vector<int> color_1(n), color_2(m);
        int cnt_1[2]{};
        int cnt_2[2]{};
        color(edges1, color_1, cnt_1);
        color(edges2, color_2, cnt_2);
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            ans[i] = cnt_1[color_1[i]] + max(cnt_2[0], cnt_2[1]);
        }
        return move(ans);
    }
};