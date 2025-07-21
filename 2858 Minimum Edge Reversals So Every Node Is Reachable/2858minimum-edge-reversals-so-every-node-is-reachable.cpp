class Solution {
public:
    vector<int> color;
    int cnt[3]{};
    int cnt_out[3]{};
    vector<vector<int>> g;
    vector<vector<int>> es;
    vector<int> ans;
    void dfs(int u, int p) {
        for (auto idx : g[u]) {
            int v = es[idx][0] ^ es[idx][1] ^ u;
            if (v == p) continue;
            bool correctDir = es[idx][0] == u;
            color[idx] = correctDir ? 1 : 2;
            cnt[color[idx]]++;
            dfs(v, u);
        }
    }
    void reroot(int u, int v, int idx) {
        bool uToV = es[idx][0] == u;
        if (uToV) {
            cnt[1]--;
            cnt[2]++;
        } else {
            cnt[1]++;
            cnt[2]--;
        }
        // swap(es[idx][0], es[idx][1]);
    }
    void dfs2(int u, int p) {
        ans[u] = cnt[2];
        for (auto idx : g[u]) {
            int v = es[idx][0] ^ es[idx][1] ^ u;
            if (v == p) continue;
            reroot(u, v, idx);
            dfs2(v, u);
            reroot(v, u, idx);
        }
    }
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        g.resize(n);
        ans.resize(n);
        color.resize(n - 1);
        es = edges;
        for (int i = 0; i < n - 1; i++) {
            g[es[i][0]].push_back(i);
            g[es[i][1]].push_back(i);
        }
        dfs(0, -1);
        dfs2(0, -1);
        return ans;
    }
};