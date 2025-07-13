struct DSU {
    vector<int> parent, size;
    DSU(int n) {
        parent.resize(n + 1);
        iota(parent.begin(), parent.end(), 0);
        size.assign(n + 1, 1);
    }
    int find(int x) {
        return x == parent[x] ? x : parent[x] = find(parent[x]);
    }
    bool unite(int a, int b) {
        int pa = find(a);
        int pb = find(b);
        if (pa != pb) {
            if (size[pa] < size[pb]) swap(pa, pb);
            size[pa] += size[pb];
            parent[pb] = pa;
            return true;
        } else
            return false;
    }
};
class Solution {
public:
    int cntComponents(int T, int n, vector<vector<int>> &edges) {
        DSU dsu(n);
        int compo = n;
        for (auto &e : edges) {
            if (e[2] > T && dsu.unite(e[0], e[1])) 
                compo--;
        }
        return compo;
    }   
    int minTime(int n, vector<vector<int>>& edges, int k) {
        int l = -1, r = 1e9 + 1;
        while (r - l > 1) {
            int m = l + (r - l)/2;
            if (cntComponents(m, n, edges) >= k)
                r = m;
            else
                l = m;
        }
        return r;
    }
};