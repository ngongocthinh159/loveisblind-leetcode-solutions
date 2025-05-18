class Solution {
public:
    const int MOD = 1e9 + 7;
    unordered_map<string,int> sToId;
    unordered_map<int,string> idToS;
    int id = 0, N, M;
    string path = "";
    vector<char> moves = {'R', 'G', 'B'};
    void dfs(int i) {
        if (i == M) {
            idToS[id] = path;
            sToId[path] = id++;
            return;
        };
        for (auto &move : moves) {
            if (!path.size() || path.back() != move) {
                path += move;
                dfs(i + 1);
                path.pop_back();
            }
        }
    }
    bool check(string &s, string &t) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == t[i]) return false;
        }
        return true;
    }
    vector<vector<int>> mat_mul(vector<vector<int>> &a, vector<vector<int>> &b) {
        int x = a.size(), y = a[0].size(), z = b[0].size();
        assert(y == b.size());
        vector<vector<int>> c(x, vector<int>(z));
        for (int i = 0; i < x; i++)
            for (int k = 0; k < y; k++)
                for (int j = 0; j < z; j++) {
                    c[i][j] += 1LL * a[i][k] * b[k][j] % MOD;
                    if (c[i][j] >= MOD) c[i][j] -= MOD;
                }
        return move(c);
    }
    vector<vector<int>> mat_expo(vector<vector<int>> &mat, int p) {
        int n = mat.size();
        vector<vector<int>> res(n, vector<int>(n));
        for (int i = 0; i < n; i++) res[i][i] = 1;
        if (n == 0) return res;
        auto cur = mat;
        while (p) {
            if (p&1) {
                res = mat_mul(res, cur);
            }
            cur = mat_mul(cur, cur);
            p >>= 1;
        }
        return res;
    }
    int colorTheGrid(int m, int n) {
        N = n;
        M = m;
        dfs(0);
        vector<vector<int>> mat(id, vector<int>(id));
        for (int i = 0; i < id; i++)
            for (int j = 0; j < id; j++) if (i != j) {
                if (check(idToS[i], idToS[j]))
                    mat[i][j] = 1;
            }
        vector<vector<int>> base(id, vector<int>(1, 1));
        auto mat_pow = mat_expo(mat, n - 1);
        auto res = mat_mul(mat_pow, base);
        int ans = 0;
        for (int i = 0; i < id; i++) {
            ans += res[i][0];
            if (ans >= MOD) ans -= MOD;
        }
        return ans;
    }
};