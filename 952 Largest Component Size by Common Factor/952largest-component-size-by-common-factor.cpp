const int mxN = 1e5 + 5;
vector<int> spf(mxN, -1);
void cal_spf() {
    for (int i = 1; i < mxN; i++) {
        spf[i] = i;
    }
    for (int i = 2; i < mxN; i++) {
        if (spf[i] == i) {
            for (int j = 2*i; j < mxN; j += i) {
                spf[j] = min(spf[j], i);
            }
        }
    }
}
vector<int> get_fact(int n) {
    vector<int> res;
    while (n != 1) {
        int fact = spf[n];
        while (n%fact==0) {
            n/=fact;
        }
        res.push_back(fact);
    }
    return res;
}
bool ok = false;
struct DSU {
    vector<int> parent;
    vector<int> size;
    DSU(int n) {
        parent.resize(n + 1);
        size.resize(n + 1);
    }
    void make_set(int x) {
        if (size[x] == 0) {
            parent[x] = x;
            size[x] = 1;
        }
    }
    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    int max_size() {
        int ans = INT_MIN;
        for (auto num : size) ans = max(ans, num);
        return ans;
    }
    void unite(int a, int b) {
        int pa = find(a);
        int pb = find(b);
        if (pa != pb) {
            if (size[pa] < size[pb])
                swap(pa, pb);
            size[pa] += size[pb];
            parent[pb] = pa;
        }
    }
};
class Solution {
public:
    int largestComponentSize(vector<int>& nums) {
        if (!ok) {cal_spf(); ok = true;}
        int hasOne = false;
        unordered_map<int,unordered_set<int>> M;
        for (auto num : nums) {
            if (num == 1) {hasOne = true; continue;}
            vector<int> facts = get_fact(num);
            for (auto &f : facts) {
                M[f].insert(num);
            }
        }
        DSU dsu(mxN);
        for (auto &[fact, list] : M) {
            int x = *list.begin();
            dsu.make_set(x);
            int cnt = 0;
            for (auto &num : list) {
                if (cnt == 0) {cnt++; continue;}
                dsu.make_set(num);
                dsu.unite(x, num);
            }
        }
        return max(hasOne ? 1 : 0, dsu.max_size());
    }
};