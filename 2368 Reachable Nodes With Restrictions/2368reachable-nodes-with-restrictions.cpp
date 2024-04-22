class Solution {
public:
    int ans = 0;
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& r) {
        unordered_set<int> S(r.begin(), r.end());
        vector<vector<int>> g(n);
        for (auto &e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        vector<bool> visited(n, false);
        visited[0] = true;
        dfs(0, g, visited, S);
        return ans;
    }
    void dfs(int u, vector<vector<int>> &g, vector<bool> &visited, unordered_set<int> &S) {
        ans++;
        for (auto v : g[u]) {
            if (!visited[v] && !S.count(v)) {
                visited[v] = true;
                dfs(v, g, visited, S);
            }
        }
    }
};