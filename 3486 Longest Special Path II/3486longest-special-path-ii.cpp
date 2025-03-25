#define ll long long
#define next __next
#define MAXN 50005
int last[MAXN], pref[MAXN], height[MAXN], next[MAXN];
class Solution {
public:
    const int IINF = 1e9;
    vector<vector<pair<int,int>>> g;
    vector<int> res = {-IINF, IINF};
    void dfs(int u, int par, int dup1, int dup2, int l, vector<int> &nums) {
        if (last[nums[u]] != -1) {
            if (dup1 == -1) {
                dup2 = last[nums[u]];
                dup1 = u;
            } else {
                if (height[last[nums[u]]] > height[dup2]) {
                    l = next[dup2];
                    dup2 = last[nums[u]];
                    dup1 = u;
                } else {
                    if (height[l] <= height[last[nums[u]]]) l = next[last[nums[u]]];
                }  
            }
        }
        
        // cout << u << " " << dup1 << " " << dup2 << " " << l << "\n"; 

        if (res[0] < pref[u] - pref[l]) {
            res[0] = pref[u] - pref[l];
            res[1] = height[u] - height[l] + 1;
        } else if (res[0] == pref[u] - pref[l] && res[1] > height[u] - height[l] + 1) {
            res[1] = height[u] - height[l] + 1;
        }

        int org_last = last[nums[u]];
        last[nums[u]] = u;
        for (auto &[v, w] : g[u]) if (v != par) {
            height[v] = height[u] + 1;
            pref[v] = pref[u] + w;
            next[u] = v;
            dfs(v, u, dup1, dup2, l, nums);
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
        for (int i = 0; i < nums.size(); i++) last[nums[i]] = -1;
        dfs(0, -1, -1, -1, 0, nums);
        return res;
    }
};