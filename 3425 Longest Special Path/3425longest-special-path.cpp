#define ll long long
#define MAXN 50005
#define next __next
int last[MAXN], pref[MAXN], next[MAXN], height[MAXN];
class Solution {
public:
    const int IINF = 1e9;
    vector<vector<pair<int,int>>> g;
    vector<int> res = {-IINF, IINF};
    void dfs(int u, int par, int l, vector<int> &nums) {
        if (last[nums[u]] != -1 && height[l] <= height[last[nums[u]]]) 
            l = next[last[nums[u]]];

        if (res[0] < pref[u] - pref[l]) {
            res[0] = pref[u] - pref[l];
            res[1] = height[u] - height[l] + 1;
        } else if (res[0] == pref[u] - pref[l] && res[1] > height[u] - height[l] + 1) {
            res[1] = height[u] - height[l] + 1;
        }

        int org_last = last[nums[u]];
        last[nums[u]] = u;
        for (auto &[v, w] : g[u]) if (v != par) {
            pref[v] = pref[u] + w;
            next[u] = v;
            height[v] = height[u] + 1;
            dfs(v, u, l, nums);
        }
        last[nums[u]] = org_last;
    }
    vector<int> longestSpecialPath(vector<vector<int>>& edges, vector<int>& nums) {
        int n = nums.size();
        g.resize(n);
        for (auto &e : edges) {
            g[e[0]].push_back({e[1], e[2]});
            g[e[1]].push_back({e[0], e[2]});
        }
        for (auto x : nums) last[x] = -1;
        dfs(0, -1, 0, nums);
        return res;
    }
};