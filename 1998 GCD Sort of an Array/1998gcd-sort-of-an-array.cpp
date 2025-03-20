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
#define MAXN 100005
int spf[MAXN];
auto init = []{
    for (int i = 1; i < MAXN; i++) spf[i] = i;
    for (int i = 2; i * i < MAXN; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j < MAXN; j += i) {
                spf[j] = min(spf[j], i);
            }
        }
    }
    return 0;
}();
class Solution {
public:
    bool gcdSort(vector<int>& nums) {
        int n = nums.size();
        DSU dsu(MAXN);
        for (int i = 0; i < n; i++) {
            int cur = nums[i];
            while (cur != 1) {
                int fact = spf[cur];
                while (cur % fact == 0) {
                    cur /= fact;
                }
                dsu.unite(fact, nums[i]);
            }
        }
        unordered_map<int,vector<int>> id_to_list;
        unordered_map<int,int> id_to_idx;
        for (int i = 0; i < n; i++) {
            id_to_list[dsu.find(nums[i])].push_back(i);
        }
        for (auto &[id, list] : id_to_list) {
            sort(list.begin(), list.end(), [&](int i, int j) {
                return nums[i] < nums[j];
            });
        }
        vector<int> v(n);
        for (int i = 0; i< n; i++) {
            int id = dsu.find(nums[i]);
            v[i] = nums[id_to_list[id][id_to_idx[id]]];
            id_to_idx[id]++;
        }
        bool res = true;
        for (int i = 1; i < n; i++) {
            if (v[i] < v[i - 1]) {
                res = false;
                break;
            }
        }
        return res;
    }
};