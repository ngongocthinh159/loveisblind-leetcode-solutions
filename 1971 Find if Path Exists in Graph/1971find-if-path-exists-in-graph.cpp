class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> g(n);
        vector<bool> visited(n, false);
        for (auto &e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        visited[source] = true;
        dfs(source, g, visited);
        return visited[destination];
    }
    void dfs(int u, vector<vector<int>> &g, vector<bool> &visited) {
        for (auto &v : g[u]) {
            if (!visited[v]) {
                visited[v] = true;
                dfs(v, g, visited);
            }
        }
    }
};