class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<vector<int>> combinationSum3(int k, int n) {
        dfs(1, k, n);
        return res;
    }

    void dfs(int i, int k, int n) {
        if (n == 0 && k == 0) {
            res.push_back(path); return;
        }
        if (i >= 10) return;

        // skip
        dfs(i + 1, k, n);

        if (n >= i) {
            path.push_back(i);
            dfs(i + 1, k - 1, n - i);
            path.pop_back();
        }
    }
};