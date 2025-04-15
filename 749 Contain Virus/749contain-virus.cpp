class Solution {
public:
    vector<pair<int,int>> moves = {{0,1},{1,0},{-1,0},{0,-1}};
    void dfs(int i, int j, int n, int m, vector<vector<bool>> &vis, vector<vector<int>>& isInfected, int &threat, int &wall, vector<pair<int,int>> &v, vector<pair<int,int>> &nei) {
        v.push_back({i, j});
        vis[i][j] = true;
        for (auto &move : moves) {
            int I = i + move.first;
            int J = j + move.second;
            if (0 <= I && I < n && 0 <= J && J < m) {
                if (!vis[I][J] && isInfected[I][J] == 1)
                    dfs(I, J, n, m, vis, isInfected, threat, wall, v, nei);
                else if (isInfected[I][J] == 0) {
                    wall++;
                    if (!vis[I][J]) {
                        threat++;
                        vis[I][J] = true;
                        nei.push_back({I, J});
                    }
                }
            }
        }
    }
    int infect(vector<vector<int>>& isInfected) {
        int n = isInfected.size(), m = isInfected[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m));
        vector<vector<pair<int,int>>> compo;
        int wall_used = 0, mx_threat = 0, idx = -1;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) if (isInfected[i][j] == 1 && !vis[i][j]) {
                vector<pair<int,int>> v;
                vector<pair<int,int>> nei;
                int threat = 0, wall = 0;
                dfs(i, j, n, m, vis, isInfected, threat, wall, v, nei);
                compo.emplace_back(v);
                if (mx_threat < threat) {
                    mx_threat = threat;
                    wall_used = wall;
                    idx = compo.size() - 1;
                }
                for (auto &[I, J] : nei) vis[I][J] = false;
            }
        if (idx != -1) {
            for (auto &[i, j] : compo[idx]) {
                isInfected[i][j] = -1;
            }
            for (int k = 0; k < compo.size(); k++) if (k != idx) {
                for (auto &[i, j] : compo[k]) {
                    for (auto &move : moves) {
                        int I = i + move.first;
                        int J = j + move.second;
                        if (0 <= I && I < n && 0 <= J && J < m && isInfected[I][J] == 0) {
                            isInfected[I][J] = 1;
                        }
                    }
                }
            }
        }
        return wall_used;
    }
    int containVirus(vector<vector<int>>& isInfected) {
        int ans = 0;
        while (true) {
            int res = infect(isInfected);
            if (!res) break;
            ans += res;
        }
        return ans;
    }
};