class Solution {
public:
    pair<int,int> findFurthest(int src, vector<vector<int>> &g) {
        int res;
        deque<pair<int,int>> q;
        q.push_front({src, -1});
        int level = 0;
        while (q.size()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto p = q.back(); q.pop_back();
                int u = p.first;
                int par = p.second;
                res = u;
                for (auto v : g[u]) if (v != par) q.push_front({v, u});
            }
            level++;
        }
        return {res, level - 1};
    }
    int findDiameter(vector<vector<int>> &edges) {
        int n = edges.size() + 1;
        vector<vector<int>> g(n);
        for (auto &e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        int leaf = findFurthest(0, g).first;
        return findFurthest(leaf, g).second;
    }
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int dia1 = findDiameter(edges1);
        int dia2 = findDiameter(edges2);
        return max((dia1 + 1)/2 + (dia2 + 1)/2 + 1, max(dia1, dia2));
    }
};