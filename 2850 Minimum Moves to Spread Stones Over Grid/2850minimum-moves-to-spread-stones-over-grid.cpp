class Solution {
public:
    set<pair<int,int>> st;
    int res = INT_MAX;
    int minimumMoves(vector<vector<int>>& grid) {
        vector<pair<int,int>> v;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] > 1) st.insert({i,j});
                else if (grid[i][j] == 0) v.push_back({i,j});
            } 
        }
        dfs(grid, v, 0, 0);
        return res;
    }

    void dfs(vector<vector<int>>& grid, vector<pair<int,int>>& v, int i, int cur) {
        if (i == v.size()) {
            res = min(res, cur);
            return;
        }

        int curX = v[i].first;
        int curY = v[i].second;
        for (auto& p : st) {
            int nextX = p.first;
            int nextY = p.second;
            if (grid[nextX][nextY] == 1) continue;
            grid[nextX][nextY]--;
            dfs(grid, v, i + 1, cur + abs(nextX - curX) + abs(nextY - curY));
            grid[nextX][nextY]++;
        }
    }
};