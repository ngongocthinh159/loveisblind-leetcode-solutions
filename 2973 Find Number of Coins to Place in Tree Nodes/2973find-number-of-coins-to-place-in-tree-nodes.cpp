class Solution {
public:
    vector<vector<int>> mn_3;
    vector<vector<int>> mx_3;
    vector<vector<int>> g;
    vector<long long> ans;
    int n;
    vector<long long> placedCoins(vector<vector<int>>& edges, vector<int>& cost) {
        n = cost.size(); 
        g = vector<vector<int>>(n);
        ans.resize(n);
        mn_3.resize(n);
        mx_3.resize(n);
        for (auto &e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        dfs(0, -1, cost);   
        return ans;
    }
    bool compare(int x, int y, int mode) {
        if (mode == 0) return x <= y;
        else return x >= y;
    }
    void dfs(int u, int par, vector<int> &cost) {
        mn_3[u].push_back(cost[u]);
        mx_3[u].push_back(cost[u]);
        for (auto &v : g[u]) {
            if (v != par) {
                dfs(v, u, cost);
                merge(mn_3[v], mn_3[u], 0);
                merge(mx_3[v], mx_3[u], 1);
            }
        }
        long long ans_u;
        if (mn_3[u].size() < 3) ans_u = 1;
        else {
            ans_u = max(1LL*mx_3[u][2]*mx_3[u][1]*mx_3[u][0], 1LL*mn_3[u][0]*mn_3[u][1]*mx_3[u][0]);
            if (ans_u < 0) ans_u = 0;
        }
        ans[u] = ans_u;
    }
    void merge(vector<int> &mn_3, vector<int> &cur, int mode) {
        vector<int> res;
        int i = 0;
        int j = 0;
        while (i < mn_3.size() && j < cur.size() && res.size() < 3) {
            if (compare(mn_3[i], cur[j], mode)) {
                res.push_back(mn_3[i]);
                i++;
            } else {
                res.push_back(cur[j]);
                j++;
            }
        }
        if (res.size() == 3) {
            cur = res;
            return;
        }
        while (i < mn_3.size() && res.size() < 3) {
            res.push_back(mn_3[i]);
            i++;
        }
        while (j < cur.size() && res.size() < 3) {
            res.push_back(cur[j]);
            j++;
        }
        cur = res;
    }
};