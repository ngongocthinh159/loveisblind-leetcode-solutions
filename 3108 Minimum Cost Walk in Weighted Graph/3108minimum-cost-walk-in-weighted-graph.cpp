struct DSU {
    vector<int> parent, size;
    DSU(int n) {
        parent.resize(n + 1);
        iota(parent.begin(), parent.end(), 0);
        size.assign(n + 1, 1);
    }
    int find(int x) {
        return x == parent[x] ? x : x = find(parent[x]);
    }
    bool same(int a, int b) {
        return find(a) == find(b);
    }
    void unite(int a, int b) {
        int pa = find(a);
        int pb = find(b);
        if (pa != pb) {
            if (size[pa] < size[pb]) swap(pa, pb);
            size[pa] += size[pb];
            parent[pb] = pa;
        }
    }
};
class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        DSU dsu(n);
        for (auto &e : edges) {
            dsu.unite(e[0], e[1]);
        }
        vector<int> min_cost(n, -1), ans(query.size());
        for (auto &e : edges)
            min_cost[dsu.find(e[0])] &= e[2];
        for (int i = 0; i < query.size(); i++) {
            if (!dsu.same(query[i][0], query[i][1])) 
                ans[i] = -1;
            else
                ans[i] = min_cost[dsu.find(query[i][0])];
        }
        return ans;
    }
};