class Solution {
public:
    vector<int> eulerianPath;
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, multiset<int>> g;
        unordered_map<int, int> indeg;
        unordered_map<int, int> outdeg;
        unordered_set<int> vertices;
        for (auto &edge : pairs) {
            g[edge[0]].insert(edge[1]);
            outdeg[edge[0]]++;
            indeg[edge[1]]++;
            vertices.insert(edge[0]);
            vertices.insert(edge[1]);
        }
        int start = -1, end = -1;
        for (auto u : vertices) {
            if (outdeg[u] - indeg[u] == 1) {
                start = u;
                break;
            }
        }
        if (start == -1) {
            start = pairs[0][0];
        }
        dfs(start, g);
        reverse(eulerianPath.begin(), eulerianPath.end());
        vector<vector<int>> res;
        for (int i = 1; i < eulerianPath.size(); i++) {
            res.push_back({eulerianPath[i - 1], eulerianPath[i]});
        }
        return res;
    }
    void dfs(int u, unordered_map<int, multiset<int>> &g) {
        while (g[u].size()) {
            int v = *g[u].begin();
            g[u].erase(g[u].begin());
            dfs(v, g);
        }
        eulerianPath.push_back(u);
    }
};