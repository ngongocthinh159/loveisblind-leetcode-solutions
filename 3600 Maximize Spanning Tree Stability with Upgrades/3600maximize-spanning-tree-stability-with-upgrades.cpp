struct DSU {
    vector<int> parent, size;
    DSU(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        size.assign(n, 1);
    }
    int find(int x) {
        return x == parent[x] ? x : parent[x] = find(parent[x]);
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
    bool sameSet(int a, int b) {
        return find(a) == find(b);
    }
};
class Solution {
public:
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        DSU dsu(n);
        vector<vector<int>> upgradableEdges;
        int mnNonUpgradableEdge = INT_MAX;
        int uniteCnt = 0;
        for (auto &e : edges) {
            if (e[3] == 1) {
                mnNonUpgradableEdge = min(mnNonUpgradableEdge, e[2]);
                if (dsu.sameSet(e[0], e[1]))
                    return -1;
                dsu.unite(e[0], e[1]);
                uniteCnt++;
            } else {
                upgradableEdges.push_back({e[0], e[1], e[2]});
            }
        }
        if (uniteCnt == n - 1)
            return mnNonUpgradableEdge;
        sort(upgradableEdges.begin(), upgradableEdges.end(), [](vector<int> &e1, vector<int> &e2) {
            return e1[2] < e2[2];
        });
        vector<int> cEdges;
        for (int i = (int) upgradableEdges.size() - 1; i >= 0; i--) {
            auto &e = upgradableEdges[i];
            if (dsu.sameSet(e[0], e[1])) continue;
            dsu.unite(e[0], e[1]);
            uniteCnt++;
            cEdges.push_back(e[2]);
        }
        if (uniteCnt != n - 1)
            return -1;
        for (int i = (int) cEdges.size() - 1; i >= 0 && k; i--, k--) {
            cEdges[i] *= 2;
        }
        return min(*min_element(cEdges.begin(), cEdges.end()), mnNonUpgradableEdge);
    }
};