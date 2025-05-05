const int MOD = 1e9 + 7;
class Solution {
public:
    struct Matrix {
        vector<vector<int>> mat;
        int n, m;

        Matrix(int _n, int _m) {
            n = _n, m = _m;
            mat.assign(n, vector<int>(m));
        }

        Matrix(const vector<vector<int>> &_mat) {
            n = _mat.size();
            m = _mat[0].size();
            mat = _mat;
        }

        vector<int>& operator [] (int i) {
            return mat[i];
        }

        const vector<int>& operator [] (int i) const {
            return mat[i];
        }

        Matrix operator * (const Matrix& q) {
            assert(m == q.n);
            int x = n, y = m, z = q.m;
            Matrix res(x, z);
            for (int i = 0; i < x; i++)
                for (int j = 0; j < y; j++)
                    for (int k = 0; k < z; k++) {
                        res[i][k] += 1LL * mat[i][j] * q[j][k] % MOD;
                        if (res[i][k] >= MOD) res[i][k] -= MOD;
                    }
            return res;
        }
        Matrix expo(int p) {
            Matrix res = Identity();
            Matrix cur = mat;
            while (p) {
                if (p&1)
                    res = res * cur;
                cur = cur * cur;
                p >>= 1;
            }
            return res;
        }
        Matrix Identity() {
            assert(n == m);
            Matrix res(n, m);
            for (int i = 0; i < n; i++) res[i][i] = 1;
            return res;
        }
    };
    int numTilings(int n) {
        if (n == 1) return 1;
        Matrix mat({
            {1, 1, 1, 1, 0, 0},
            {0, 0, 1, 1, 0, 0},
            {0, 1, 0, 1, 0, 0},
            {1, 0, 0, 0, 0, 0},
            {0, 1, 0, 0, 0, 0},
            {0, 0, 1, 0, 0, 0}
        });
        Matrix base({{1}, {0}, {0}, {1}, {0}, {0}});
        Matrix res = mat.expo(n - 2 + 1);
        res = res * base;
        return res[0][0];
    }
};