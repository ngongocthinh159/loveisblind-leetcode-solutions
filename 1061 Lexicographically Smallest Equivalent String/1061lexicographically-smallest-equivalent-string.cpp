struct DSU {
    vector<int> parent, size, c;
    DSU(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        size.assign(n, 1);
        c.resize(n + 1);
        iota(c.begin(), c.end(), 0);
    }
    int find(int x) {
        if (x == parent[x]) return x;
        c[parent[x]] = min(c[parent[x]], c[x]);
        int res = find(parent[x]);
        return parent[x] = res;
    }
    void unite(int a, int b) {
        int pa = find(a);
        int pb = find(b);
        if (pa != pb) {
            if (size[pa] < size[pb]) swap(pa, pb);
            c[pa] = min(c[pa], c[pb]);
            size[pa] += size[pb];
            parent[pb] = pa;
        }
    }
    char find_c(char chr) {
        int pa = find(chr - 'a');
        return (char) c[pa] + 'a';
    }
};
class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.size(), m = baseStr.size();
        DSU dsu(26);
        for (int i = 0; i < n; i++) {
            dsu.unite(s1[i] - 'a', s2[i] - 'a');
        }
        string res = "";
        for (int i = 0; i < m; i++) {
            res += dsu.find_c(baseStr[i]);
        }
        return res;
    }
};