class Solution {
public:
    vector<vector<string>> res;
    vector<int> path;
    int N;
    void dfs(int i, int cnt, vector<bool> &col, vector<bool> &f1, vector<bool> &f2) {
        if (i == N) {
            if (cnt == N) {
                vector<string> cur;
                for (auto j : path) {
                    string s(N, '.');
                    s[j] = 'Q';
                    cur.emplace_back(s);
                }
                res.emplace_back(cur);
            }
            return;
        }

        // choose
        for (int j = 0; j < N; j++) {
            if (!col[j] && !f1[i + j] && !f2[i - j + N] && cnt < N) {
                col[j] = 1;
                f1[i + j] = 1;
                f2[i - j + N] = 1;
                path.push_back(j);
                dfs(i + 1, cnt + 1, col, f1, f2);
                path.pop_back();
                col[j] = 0;
                f1[i + j] = 0;
                f2[i - j + N] = 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        N = n;
        vector<bool> col(n), f1(3*n), f2(3*n);
        dfs(0, 0, col, f1, f2);
        return move(res);
    }
};