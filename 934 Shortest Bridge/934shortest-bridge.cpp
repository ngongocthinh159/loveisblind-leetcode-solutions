class Solution {
public:
    vector<vector<bool>> visited;
    deque<pair<int,int>> q;
    int shortestBridge(vector<vector<int>>& grid) {
        visited = vector<vector<bool>>(grid.size(), vector<bool>(grid[0].size(), false));
        for (int i = 0; i < grid.size(); i++) {
            bool shouldBreak = false;
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    visited[i][j] = true;
                    q.push_front({i,j});
                    dfs(grid, i, j);
                    shouldBreak = true;
                    break;
                }
            }
            if (shouldBreak) break;
        }

        int cnt = 0;
        while (q.size()) {
            int levelSize = q.size();
            for (int i = 0; i < levelSize; i++) {
                auto cur = q.back();
                q.pop_back();

                for (auto& p : moves) {
                    int nextI = cur.first + p.first;
                    int nextJ = cur.second + p.second;
                    if (0 <= nextI && nextI < grid.size() && 0 <= nextJ && nextJ < grid[0].size()) {
                        if (!visited[nextI][nextJ]) {
                            if (grid[nextI][nextJ] == 1) return cnt;
                            visited[nextI][nextJ] = true;
                            q.push_front({nextI, nextJ});
                        }
                    }
                }
            }
            cnt++;
        }
        return -1;
    }
    vector<pair<int,int>> moves = {{-1,0},{0,-1},{0,1},{1,0}};
    void dfs(vector<vector<int>>& grid, int i, int j) {
        for (auto& p : moves) {
            int nextI = i + p.first;
            int nextJ = j + p.second;
            if (0 <= nextI && nextI < grid.size() && 0 <= nextJ && nextJ < grid[0].size()) {
                if (!visited[nextI][nextJ] && grid[nextI][nextJ] == 1) {
                    visited[nextI][nextJ] = true;
                    q.push_front({nextI, nextJ});
                    dfs(grid, nextI, nextJ);
                }
            }
        }
    }

};