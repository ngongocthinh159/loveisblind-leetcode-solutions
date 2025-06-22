#define ll long long
class Solution {
public:
    int ans = 0;
    vector<vector<int>> g;
    vector<ll> pref;
    ll mxLeaf;
    ll findmax(int u, int p, vector<int> &cost) {
        ll res = pref[u];
        for (auto v : g[u]) if (v != p) {
            pref[v] = pref[u] + cost[v];
            res = max(res, findmax(v, u, cost));
        }
        return res;
    }
    pair<ll,bool> dfs(int u, int p, vector<int> &cost) {
        if (g[u].size() == 0 || (g[u].size() == 1 && g[u][0] == p)) {
            return {pref[u], true};
        }
        bool all = true;
        bool allEqual = true;
        ll x = -1;
        vector<pair<ll,bool>> tmp;
        for (auto v : g[u]) if (v != p) {
            tmp.push_back(dfs(v, u, cost));
            auto [val, ok_v] = tmp.back();
            all &= ok_v;
            if (ok_v) {
                if (x == -1) x = val;
                else {
                    allEqual &= (x == val);
                }
            }
        }
        if (all && allEqual) {
            return {x, true};
        }

        for (int i = 0; i < (int) tmp.size(); i++) {
            if (tmp[i].second && tmp[i].first != mxLeaf) ans++;
        }
        return {-2, false};
    }
    int minIncrease(int n, vector<vector<int>>& edges, vector<int>& cost) {
        g.resize(n);
        pref.resize(n);
        for (auto &e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        pref[0] = cost[0];
        mxLeaf = findmax(0, -1, cost);
        dfs(0, -1, cost);
        return ans;
    }
};