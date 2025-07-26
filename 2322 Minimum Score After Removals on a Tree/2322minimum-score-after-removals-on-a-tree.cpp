class Solution {
public:
    vector<int> subx, tin, tout, dep;
    vector<vector<int>> g;
    int n, totx = 0, T = -1;
    vector<int> buf;
    void dfs(int u, int p, vector<int> &nums) {
        tin[u] = ++T;
        subx[u] = nums[u];
        totx ^= nums[u];
        for (auto v : g[u]) if (v != p) {
            dep[v] = dep[u] + 1;
            dfs(v, u, nums);
            subx[u] ^= subx[v];
        }
        tout[u] = T;
    }
    bool isDescendant(int u, int v) { // v is descendant of u?
        return tin[u] < tin[v] && tout[v] <= tout[u];
    }
    int cal() {
        return max(buf[0], max(buf[1], buf[2])) - min(buf[0], min(buf[1], buf[2]));
    }
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        n = nums.size();
        g.resize(n);
        subx.resize(n);
        tin.resize(n);
        tout.resize(n);
        dep.resize(n);
        buf.resize(3);
        for (auto &e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        dfs(0, -1, nums);
        int ans = INT_MAX;
        for (int i = 0; i < n - 1; i++)
            for (int j = i + 1; j < n - 1; j++) {
                auto [u1, p1] = make_pair(edges[i][0], edges[i][1]);
                auto [u2, p2] = make_pair(edges[j][0], edges[j][1]);
                if (dep[u1] < dep[p1]) swap(u1, p1);
                if (dep[u2] < dep[p2]) swap(u2, p2);
                if (isDescendant(u1, u2) || isDescendant(u2, u1)) {
                    if (isDescendant(u2, u1)) swap(u1, u2);
                    buf[0] = subx[u2];
                    buf[1] = subx[u1] ^ buf[0];
                    buf[2] = totx ^ buf[0] ^ buf[1];
                } else {
                    buf[0] = subx[u1];
                    buf[1] = subx[u2];
                    buf[2] = totx ^ buf[0] ^ buf[1];
                }
                ans = min(ans, cal());
            }
        return ans;
    }
};