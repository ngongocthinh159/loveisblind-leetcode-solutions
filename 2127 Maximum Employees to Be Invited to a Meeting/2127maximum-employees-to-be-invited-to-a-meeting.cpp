#define MAX 100005
enum State {UNKNOWN, VISITED, ACTIVE};
State states[MAX];
int depth[MAX], indeg[MAX], cycle_len, k, t;
class Solution {
public:
    void dfs(int u, vector<vector<int>> &g, int cur_depth) {
        states[u] = ACTIVE;
        depth[u] = cur_depth;
        for (auto v : g[u]) {
            if (states[v] == ACTIVE)
                cycle_len = cur_depth - depth[v] + 1,
                k = u, t = v;
            else if (states[v] == UNKNOWN) 
                dfs(v, g, cur_depth + 1);
        }
        states[u] = VISITED;
    }
    int dfs2(int u, int par, vector<vector<int>> &g) {
        int res = 0;
        for (auto v : g[u]) if (v != par)
            res = max(res, 1 + dfs2(v, u, g));
        return res;
    }
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        vector<vector<int>> g(n);
        vector<vector<int>> rg(n);
        memset(states, UNKNOWN, sizeof(int)*n);
        for (int i = 0; i < n; i++) 
            g[i].push_back(favorite[i]),
            rg[favorite[i]].push_back(i);
        int mx_cycle_len = 0, sum_cycle_two = 0;
        for (int i = 0; i < n; i++) if (states[i] == UNKNOWN) {
            cycle_len = -1;
            dfs(i, g, 0);
            if (cycle_len != -1) {
                mx_cycle_len = max(mx_cycle_len, cycle_len);
                if (cycle_len == 2)
                    sum_cycle_two += dfs2(k, t, rg) + dfs2(t, k, rg) + 2;
            }
        }
        return max(mx_cycle_len, sum_cycle_two);
    }
};