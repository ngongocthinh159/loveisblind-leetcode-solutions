class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<vector<int>> combine(int n, int k) {
        dfs(1, n, k);
        return res;
    }
    void dfs(int i, int n, int k) {
        if (k <= 0) {
            res.push_back(path);
            return;
        }
        if (i > n) return;

        for (int j = i; j <= n; j++) {
            path.push_back(j);
            dfs(j + 1, n, k - 1);
            path.pop_back();
        }
    }
};