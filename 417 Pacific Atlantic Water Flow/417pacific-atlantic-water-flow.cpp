class Solution {
public:
    vector<pair<int,int>> moves = {{1,0},{0,1},{-1,0},{0,-1}};
    void bfs(deque<pair<int,int>> &q, vector<vector<bool>> &vis, vector<vector<int>>& h) {
        for (auto &p : q) vis[p.first][p.second] = true;
        int n = vis.size(), m = vis[0].size(); 
        while (q.size()) {
            int sz = q.size();
            while (sz--) {
                auto p = q.back(); q.pop_back();
                int i = p.first;
                int j = p.second;
                for (auto &move : moves) {
                    int I = i + move.first;
                    int J = j + move.second;
                    if (0 <= I && I < n && 0 <= J && J < m && !vis[I][J] && h[I][J] >= h[i][j]) {
                        vis[I][J] = true;
                        q.push_front({I, J});
                    }
                }
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        deque<pair<int,int>> q1, q2;
        for (int j = 0; j < m; j++) q1.push_back({0, j});
        for (int i = 1; i < n; i++) q1.push_back({i, 0});
        for (int j = 0; j < m; j++) q2.push_back({n - 1, j});
        for (int i = 0; i < n - 1; i++) q2.push_back({i, m - 1});
        vector<vector<bool>> vis1(n, vector<bool>(m));
        vector<vector<bool>> vis2(n, vector<bool>(m));
        bfs(q1, vis1, heights);
        bfs(q2, vis2, heights);
        vector<vector<int>> res;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) if (vis1[i][j] && vis2[i][j])
                res.push_back({i, j});
        return res;
    }
};