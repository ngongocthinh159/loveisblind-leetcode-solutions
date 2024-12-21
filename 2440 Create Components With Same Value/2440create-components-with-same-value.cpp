class Solution {
public:
    unordered_set<int> sums;
    vector<vector<int>> g;
    int n;
    int dfs2(int u, int par, int sum, int &ans, vector<int>& nums) {
        int cur_sum = nums[u];
        for (auto v : g[u]) if (v != par) {
            cur_sum += dfs2(v, u, sum, ans, nums);
        }
        if (ans == -1) return -1;
        if (cur_sum > sum || (u == 0 && cur_sum != sum)) {
            ans = -1;
            return -1;
        }
        if (cur_sum == sum) {
            ans++;
            return 0;
        }
        return cur_sum;
    }
    int find_ans(int sum, vector<int>& nums) {
        int ans = 0;
        dfs2(0, -1, sum, ans, nums);
        return ans;
    }
    int componentValue(vector<int>& nums, vector<vector<int>>& edges) {
        n = nums.size();
        g.resize(n);
        int tot_sum = 0;
        for (auto x : nums) tot_sum += x;
        for (auto &e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        int res = -1;
        for (int sum = 1; sum <= sqrt(tot_sum); sum++) {
            if (tot_sum % sum == 0) {
                res = max(res, find_ans(sum, nums));
                if (tot_sum/sum != sum) {
                    res = max(res, find_ans(tot_sum/sum, nums));
                }
            }
        }
        return res - 1;
    }
};