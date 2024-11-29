#define ll long long
class Solution {
public:
    vector<vector<int>> moves = {{0,1},{1,0},{0,-1},{-1,0}};
    int minimumTime(vector<vector<int>>& grid) {
        if (grid[0][1] >= 2 && grid[1][0] >= 2) return -1;

        set<pair<ll,pair<int,int>>> S;
        int n = grid.size();
        int m = grid[0].size();
        ll LINF = 1e18;
        vector<vector<bool>> visited();
        vector<vector<ll>> dist(n, vector<ll>(m, LINF));
        S.insert({0, {0,0}});
        dist[0][0] = 0;
        while (S.size()) {
            auto p = *S.begin();
            S.erase(S.begin());
            ll w_u = p.first;
            int i = p.second.first;
            int j = p.second.second;

            for (auto &move : moves) {
                int I = move[0] + i;
                int J = move[1] + j;
                if (0 <= I && I < n && 0 <= J && J < m) {
                    int w_v = w_u >= grid[I][J] ? w_u + 1 : ((grid[I][J] - w_u) % 2 == 0 ? grid[I][J] + 1 : grid[I][J]);
                    if (dist[I][J] > w_v) {
                        S.erase({dist[I][J], {I, J}});
                        dist[I][J] = w_v;
                        S.insert({dist[I][J], {I, J}});
                    }
                }
            }
        }
        return dist[n - 1][m - 1];
    }
};