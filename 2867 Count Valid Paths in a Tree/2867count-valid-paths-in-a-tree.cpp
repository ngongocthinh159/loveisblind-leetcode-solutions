const int mxn = 1e5 + 5;
vector<bool> isPrime(mxn + 1, true);
void pre_process() {
    isPrime[1] = false;
    for (int i = 2; i*i <= mxn; i++) {
        if (isPrime[i]) {
            for (int j = i*i; j <= mxn; j += i) {
                isPrime[j] = false;
            }
        }
    }
}
bool called = false;

class Solution {
public:
    vector<vector<int>> g;
    vector<int> node_0_cnt;
    long long ans = 0;
    long long countPaths(int n, vector<vector<int>>& edges) {
        if (!called) {called = true; pre_process();}
        g = vector<vector<int>>(n + 1);
        node_0_cnt.resize(n + 1);
        for (auto &e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        dfs1(1, -1);
        dfs2(1, -1, 0);
        return ans;
    }
    void dfs1(int u, int par) {
        if (!isPrime[u]) node_0_cnt[u] = 1;
        for (auto &v : g[u]) {
            if (v != par) {
                dfs1(v, u);
                if (isPrime[u]) {
                    node_0_cnt[u] = 0;
                } else {
                    node_0_cnt[u] += node_0_cnt[v];
                }
            }
        }
    }
    void dfs2(int u, int par, int out_u) {
        vector<int> childs;
        long long sum = 0;
        for (auto &v : g[u]) {
            if (v != par) {
                childs.push_back(node_0_cnt[v]);
                sum += node_0_cnt[v];

                int out_v = isPrime[u] ? 0 : (node_0_cnt[u] - node_0_cnt[v] + out_u);
                dfs2(v, u, out_v);
            }
        }
        if (isPrime[u]) {
            childs.push_back(out_u);
            sum += out_u;

            long long tmp = -1;
            for (auto &x : childs) {
                if (x == 0) continue;
                if (tmp == -1) tmp = 1;
                tmp += 1LL*(sum - x)*x;
            }
            if (tmp != -1) {
                tmp /= 2;
                ans += tmp;
            }
            ans += sum;
        }
    }
};