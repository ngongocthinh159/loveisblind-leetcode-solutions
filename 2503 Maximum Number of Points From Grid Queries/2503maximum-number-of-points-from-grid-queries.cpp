class Solution {
public:
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    struct compare {
        bool operator() (pair<int,pair<int,int>> &p1, pair<int,pair<int,int>> &p2) {
            return p2.first < p1.first;
        }
    };
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int n = grid.size(), m = grid[0].size(), k = queries.size();
        vector<pair<int,int>> limit_to_point;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,compare> q;
        vector<vector<bool>> visited(n, vector<bool>(m));
        q.push({grid[0][0], {0,0}});
        visited[0][0] = true;
        int cur_limit = -1, cur_point = 0;
        while (q.size()) {
            cur_limit = max(q.top().first + 1, cur_limit);
            while (q.size() && q.top().first < cur_limit) {
                auto p = q.top(); q.pop();
                cur_point++;
                int x = p.second.first;
                int y = p.second.second;
                for (int i = 0; i < 4; i++) {
                    int X = x + dx[i];
                    int Y = y + dy[i];
                    if (0 <= X && X < n && 0 <= Y && Y < m && !visited[X][Y]) {
                        visited[X][Y] = true;
                        q.push({grid[X][Y], {X,Y}});
                    }
                }
            }
            limit_to_point.push_back({cur_limit, cur_point});
        }
        vector<int> res(k);
        for (int i = 0; i < k; i++) {
            auto it = upper_bound(limit_to_point.begin(), limit_to_point.end(), make_pair(queries[i], (int) 1e9));
            int idx = it - limit_to_point.begin();
            res[i] = --idx >= 0 ? limit_to_point[idx].second : 0;
        }
        return res;
    }
};