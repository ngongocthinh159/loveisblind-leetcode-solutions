class Solution {
public:
    unordered_map<string,int> dp;
    int n, m;
    vector<vector<int>> moves = {{1,-1,-1}, {1,-1,0}, {1,-1,1}, {1,0,-1}, {1,0,0}, {1,0,1}, {1,1,-1}, {1,1,0}, {1,1,1}};
    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size(); m = grid[0].size();
        return dfs(0,0,m-1,grid);
    }
    string buildKey(int x, int y1, int y2) {
        return to_string(x) + "#" + to_string(y1) + "#" + to_string(y2);
    }
    int dfs(int x, int y1, int y2, vector<vector<int>> &grid) {
        string key = buildKey(x,y1,y2);
        if (dp.count(key)) return dp[key];

        int cur = y1==y2 ? grid[x][y1] : grid[x][y1] + grid[x][y2];
        int res = cur;
        for (auto &move: moves) {
            int X = x + move[0];
            int Y1 = y1 + move[1];
            int Y2 = y2 + move[2];
            if (0 <= X && X < n && 0 <= Y1 && Y1 < m && 0 <= Y2 && Y2 < m) {
                res = max(res, cur + dfs(X,Y1,Y2,grid));
            }
        }
        return dp[key] = res;
    }
};