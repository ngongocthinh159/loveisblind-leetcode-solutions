class Solution {
public:
    bool all_type(int v[4], vector<vector<int>>& grid, int type) {
        bool res = true;
        for (int i = v[0]; i <= v[1]; i++) {
            for (int j = v[2]; j <= v[3]; j++) if (!(grid[i][j] == type || grid[i][j] == -1)) {
                res = false;
                break;
            }
            if (!res) break;
        }
        if (res) {
            for (int i = v[0]; i <= v[1]; i++)
                for (int j = v[2]; j <= v[3]; j++)
                    grid[i][j] = -1;
        }
        return res;
    }
    bool isPrintable(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        const int IINF = 1e9 + 5;
        unordered_map<int,int[4]> compo; // top, bot, left, right
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                if (!compo.count(grid[i][j])) {
                    compo[grid[i][j]][0] = IINF;
                    compo[grid[i][j]][1] = -IINF;
                    compo[grid[i][j]][2] = IINF;
                    compo[grid[i][j]][3] = -IINF;
                }
                auto &v = compo[grid[i][j]];
                v[0] = min(v[0], i);
                v[1] = max(v[1], i);
                v[2] = min(v[2], j);
                v[3] = max(v[3], j);
            }
        while (compo.size()) {
            bool found = false;
            int _type = -1;
            for (auto &[type, v] : compo) {
                if (all_type(v, grid, type)) {
                    found = true;
                    _type = type;
                    break;
                }
            }
            if (!found)
                break;
            else
                compo.erase(_type);
        }
        return compo.size() == 0;
    }
};