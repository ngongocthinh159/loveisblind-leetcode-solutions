class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int n = heightMap.size();
        int m = heightMap[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m));
        unordered_set<int> uniq;
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < m; j++) {
                uniq.insert(heightMap[i][j]);
            }
        vector<int> heights(uniq.begin(), uniq.end());
        sort(heights.begin(), heights.end());

        vector<pair<int,int>> moves = {{0,1},{1,0},{0,-1},{-1,0}};
        unordered_map<int,vector<pair<int,int>>> M;
        set<pair<int,pair<int,int>>> S;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                    M[heightMap[i][j]].push_back({i, j});
                }
            }

        int ans = 0;
        for (int j = 0; j < heights.size(); j++) {
            int curHeight = heights[j];

            for (auto &p : M[curHeight]) {
                S.insert({curHeight, p});
                visited[p.first][p.second] = true;
            }

            while (S.size() && (*S.begin()).first <= curHeight) {
                auto p = *S.begin();
                S.erase(S.begin());
                int x = p.second.first;
                int y = p.second.second;
                for (auto &move : moves) {
                    int X = x + move.first;
                    int Y = y + move.second;
                    if (0 <= X && X < n && 0 <= Y && Y < m) {
                        if (!visited[X][Y]) {
                            visited[X][Y] = true;
                            S.insert({heightMap[X][Y], {X, Y}});
                            if (heightMap[X][Y] < curHeight) {
                                ans += curHeight - heightMap[X][Y];
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};