class Solution {
public:
    vector<pair<int,int>> moves = {{1,0},{0,1},{-1,0},{0,-1}};
    int shortestPathAllKeys(vector<string>& grid) {
        int n = grid.size(), m = grid[0].size(), k = 0;
        int x_s = 0, y_s = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '@') x_s = i, y_s = j;
                if ('a' <= grid[i][j] && grid[i][j] <= 'z') k++;
            }
        vector<vector<vector<bool>>> vis(n, 
            vector<vector<bool>>(m,
                vector<bool>(1 << k)));
        deque<pair<int,pair<int,int>>> q;
        q.push_back({0, {x_s, y_s}});
        vis[x_s][y_s][0] = true;
        int level = 0;
        while (q.size()) {
            int sz = q.size();
            while (sz--) {
                auto p = q.back(); q.pop_back();
                int keys = p.first;
                int i = p.second.first;
                int j = p.second.second;
                if (keys == (1 << k) - 1)
                    return level;
                for (auto &move : moves) {
                    int I = i + move.first;
                    int J = j + move.second;
                    if (0 <= I && I < n && 0 <= J && J < m) {
                        if (grid[I][J] == '#') continue;
                        else {
                            if ('A' <= grid[I][J] && grid[I][J] <= 'Z') { // lock
                                if (!((keys >> (grid[I][J] - 'A')) & 1)) continue;
                                else if (!vis[I][J][keys]) {
                                    vis[I][J][keys] = true;
                                    q.push_front({keys, {I, J}});
                                }
                            } else if (grid[I][J] == '.' || grid[I][J] == '@') {
                                if (!vis[I][J][keys]) {
                                    vis[I][J][keys] = true;
                                    q.push_front({keys, {I, J}});
                                }
                            } else if ('a' <= grid[I][J] && grid[I][J] <= 'z') { // key
                                if (!vis[I][J][keys | (1 << (grid[I][J] - 'a'))]) {
                                    vis[I][J][keys | (1 << (grid[I][J] - 'a'))] = true;
                                    q.push_front({keys | (1 << (grid[I][J] - 'a')), {I, J}});
                                }
                            }
                        }
                    } 
                }
            }
            level++;
        }
        return -1;
    }
};