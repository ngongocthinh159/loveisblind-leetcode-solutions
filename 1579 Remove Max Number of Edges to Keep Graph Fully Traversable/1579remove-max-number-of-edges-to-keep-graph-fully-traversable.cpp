struct DSU {
    vector<int> size;
    vector<int> par;
    DSU(int n) {
        size.resize(n);
        par.resize(n);
        for (int i = 0; i < n; i++) {
            size[i] = 1;
            par[i] = i;
        }
    }
    void make_set(int x) {
        size[x] = 1;
        par[x] = x;
    }
    int find(int x) {
        if (par[x] == x) return x;
        return par[x] = find(par[x]);
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
            par[pb] = pa;
        }
    }
};
class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DSU dsu_a(n + 1);
        DSU dsu_b(n + 1);
        vector<vector<int>> eb;
        vector<vector<int>> er;
        vector<vector<int>> eg;
        int type, u, v;
        for (int i = 0; i < edges.size(); i++) {
            type = edges[i][0];
            if (type == 1) er.push_back(edges[i]);
            else if (type == 2) eg.push_back(edges[i]);
            else eb.push_back(edges[i]);
        }
        int cnt = 0;
        for (int i = 0; i < eb.size(); i++) {
            u = eb[i][1], v = eb[i][2];
            if (!dsu_a.same(u, v)) {
                dsu_a.unite(u, v);
                dsu_b.unite(u, v);
                cnt++;
            }
        }
        int cntA = 0, cntB = 0;
        for (int i = 0; i < er.size(); i++) {
            u = er[i][1], v = er[i][2];
            if (!dsu_a.same(u, v)) {
                dsu_a.unite(u, v);
                cntA++;
            }
        }
        for (int i = 0; i < eg.size(); i++) {
            u = eg[i][1], v = eg[i][2];
            if (!dsu_b.same(u, v)) {
                dsu_b.unite(u, v);
                cntB++;
            } 
        }
        if (cnt + cntA == n - 1 && cnt + cntB == n - 1) {
            return edges.size() - (cnt + cntA + cntB);
        } else return -1;
    }
};