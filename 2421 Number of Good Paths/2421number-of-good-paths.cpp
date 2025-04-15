struct DSU {
    vector<int> parent, size;
    vector<unordered_map<int,int>> freq;
    DSU(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        size.assign(n, 1);
        freq.resize(n);
    }
    int find(int x) {
        return x == parent[x] ? x : parent[x] = find(parent[x]);
    }
    void unite(int a, int b, int val) {
        int pa = find(a);
        int pb = find(b);
        if (pa != pb) {
            if (size[pa] < size[pb]) swap(a, b), swap(pa, pb);
            size[pa] += size[pb];
            parent[pb] = pa;
            freq[pa][val] += freq[pb][val];
        }
    }
    int get_freq(int u, int val) {
        return freq[u][val];
    }
    void incr(int u, int val) {
        freq[u][val]++;
    }
};
class Solution {
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        vector<vector<int>> g(n);
        for (auto &e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        map<int,vector<int>> val_to_nodes;
        for (int i = 0; i < n; i++) {
            val_to_nodes[vals[i]].push_back(i);
        }
        DSU dsu(n);
        int ans = n;
        for (auto &[val, nodes] : val_to_nodes) {
            unordered_set<int> pa;
            for (auto u : nodes) {
                dsu.incr(u, val);
            }
            for (auto u : nodes) {
                for (auto v : g[u]) if (vals[v] <= val) {
                    dsu.unite(u, v, val);
                }
            }
            for (auto u : nodes) pa.insert(dsu.find(u));
            for (auto u : pa) {
                int f = dsu.get_freq(u, val);
                ans += f * (f - 1) / 2;
            }
        }
        return ans;
    }
};