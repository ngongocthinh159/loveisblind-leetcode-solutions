class Solution {
public:
    vector<int> res;
    void dfs(int cur, int n) {
        for (int i = cur != 0 ? 0 : 1; i <= 9; i++) {
            int nxt = cur * 10 + i;
            if (nxt <= n) {
                res.push_back(nxt);
                dfs(nxt, n);
            } else
                break;
        }
    }
    vector<int> lexicalOrder(int n) {
        dfs(0, n);
        return res;
    }
};