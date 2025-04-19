class Solution {
public:
    const int IINF = 1e9 + 5;
    vector<pair<int,int>> moves = {{1,0},{0,1},{-1,0},{0,-1}};
    void fill_mat(vector<vector<int>> &mat, int state) {
        int n = mat.size(), m = mat[0].size();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                mat[i][j] = 0;
                if ((state >> (i*m + j)) & 1)
                    mat[i][j] = 1;
            }
    }
    int get_state(vector<vector<int>> &mat) {
        int res = 0, n = mat.size(), m = mat[0].size();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) if (mat[i][j])
                res |= (1 << (i*m + j));
        return res;
    }
    int minFlips(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int N = n * m;
        vector<bool> vis(1 << N);
        vector<vector<int>> tmat(n, vector<int>(m));
        vector<pair<int,int>> used;
        int src = get_state(mat);
        deque<int> q;
        vis[src] = true;
        q.push_front(src);
        int steps = 0;
        while (q.size()) {
            int sz = q.size();
            while (sz--) {
                int u = q.back(); 
                q.pop_back();
                if (u == 0)
                    return steps;
                fill_mat(tmat, u);
                for (int i = 0; i < n; i++)
                    for (int j = 0; j < m; j++) {
                        tmat[i][j] ^= 1;
                        for (auto &move : moves) {
                            int I = i + move.first;
                            int J = j + move.second;
                            if (0 <= I && I < n && 0 <= J && J < m) {
                                tmat[I][J] ^= 1;
                                used.push_back({I, J});
                            }
                        }

                        int v = get_state(tmat);
                        if (!vis[v]) {
                            vis[v] = true;
                            q.push_front(v);
                        }

                        tmat[i][j] ^= 1;
                        for (auto [I, J] : used) tmat[I][J] ^= 1;
                        used.clear();
                    }
            }
            steps++;
        }
        return -1;
    }
};