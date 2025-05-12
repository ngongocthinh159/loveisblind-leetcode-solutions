#define ll long long
#define MAXN 50005
#define MAXK 55
ll dp[MAXN][2][MAXK];
class Solution {
public:
    vector<vector<int>> g;
    int n, K;
    ll const LINF = 4e18 + 5;
    long long subtreeInversionSum(vector<vector<int>>& edges, vector<int>& nums, int k) {
        n = nums.size();
        K = k;
        g.resize(n);
        for (auto &e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        dfs(0, -1, nums);
        return dp[0][0][K];
    }
    void dfs(int u, int p, vector<int> &nums) {

        for (auto v : g[u]) if (v != p) {
            dfs(v, u, nums);
        }

        for (int parity = 0; parity < 2; parity++)
            for (int dist = 1; dist <= K; dist++) {
                int sign = parity == 0 ? 1 : -1;

                // not inverse
                ll res1 = sign * nums[u];
                for (auto v : g[u]) if (v != p) {
                    res1 += dp[v][parity][min(dist + 1, K)];
                }

                // inverse
                ll res2 = -LINF;
                if (dist == K) {
                    res2 = sign * nums[u] * -1;
                    for (auto v : g[u]) if (v != p) {
                        res2 += dp[v][parity^0^1][1];
                    }
                }

                dp[u][parity][dist] = max(res1, res2);
            }
    }
};