class Solution {
public:
    vector<pair<int,int>> moves = {{0,1},{1,0},{-1,0},{0,-1}};
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        int t = 0;
        set<pair<int,pair<int,int>>> q;
        vector<vector<bool>> vis(n, vector<bool>(m));
        q.insert({0,{0,0}});
        vis[0][0] = true;
        while (q.size()) {
            auto p = *q.begin();
            q.erase(q.begin());
            int time = p.first;
            int i = p.second.first;
            int j = p.second.second;
            t = max(t, time);
            if (i == n - 1 && j == m - 1)
                return t;
            for (auto &move : moves) {
                int I = move.first + i;
                int J = move.second + j;
                if (0 <= I && I < n && 0 <= J && J < m && !vis[I][J]) {
                    vis[I][J] = true;
                    if (moveTime[I][J] + 1 > t + 1) 
                        q.insert({moveTime[I][J] + 1, {I, J}});
                    else
                        q.insert({t + 1, {I, J}});
                }
            }
        }
        return -1;
    }
};