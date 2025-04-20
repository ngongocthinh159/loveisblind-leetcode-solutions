class Solution {
public:
    const int IINF = 1e9;
    vector<pair<int,int>> moves = {{1,0},{0,1},{-1,0},{0,-1}};
    bool check(int x, vector<vector<int>> &grid) {
        int n = grid.size(), m = grid[0].size();
        deque<pair<int,int>> q;
        vector<vector<bool>> vis(n, vector<bool>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) if (grid[i][j] == 1) {
                vis[i][j] = 1;
                q.push_front({i, j});
            }
        int CNT = x;
        while (x--) {
            int sz = q.size();
            while (sz--) {
                auto p = q.back(); q.pop_back();
                int i = p.first;
                int j = p.second;
                for (auto &move : moves) {
                    int I = i + move.first;
                    int J = j + move.second;
                    if (0 <= I && I < n && 0 <= J && J < m && !vis[I][J] && grid[I][J] != 2) {
                        if (I == 0 && J == 0)
                            return false;
                        vis[I][J] = true;
                        q.push_front({I, J});
                    }
                }
            }
        }

        deque<pair<int,int>> q2;
        vector<vector<bool>> vis2(n, vector<bool>(m));
        vis2[0][0] = true;
        q2.push_front({0, 0});
        while (q2.size()) {
            int sz = q2.size();
            while (sz--) {
                auto p = q2.back(); q2.pop_back();
                int i = p.first;
                int j = p.second;
                if (!vis2[i][j]) continue;
                for (auto &move : moves) {
                    int I = i + move.first;
                    int J = j + move.second;
                    if (0 <= I && I < n && 0 <= J && J < m && grid[I][J] == 0 && !vis[I][J] && !vis2[I][J]) {
                        if (I == n - 1 && J == m - 1)
                            return true;
                        vis2[I][J] = true;
                        q2.push_front({I, J});
                    }
                }
            }

            sz = q.size();
            while (sz--) {
                auto p = q.back(); q.pop_back();
                int i = p.first;
                int j = p.second;
                for (auto &move : moves) {
                    int I = i + move.first;
                    int J = j + move.second;
                    if (0 <= I && I < n && 0 <= J && J < m && grid[I][J] != 2 && !vis[I][J]) {
                        if (vis2[I][J]) vis2[I][J] = false;
                        vis[I][J] = true;
                        q.push_front({I, J});
                    }
                }
            }
        }
        return false;
    }
    int maximumMinutes(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int l = -1, r = n*m + 1;
        while (r - l > 1) {
            int mid = l + (r - l)/2;
            if (check(mid, grid))
                l = mid;
            else
                r = mid;
        }
        return l == n*m ? IINF : l;
    }
};