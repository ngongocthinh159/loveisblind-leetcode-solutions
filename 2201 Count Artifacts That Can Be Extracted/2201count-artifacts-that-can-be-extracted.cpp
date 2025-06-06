class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
        int m = artifacts.size();
        vector<vector<int>> grid(n, vector<int>(n));
        vector<int> cnt(m + 1);
        int id = 1;
        for (auto &a : artifacts) {
            int tot = 0;
            for (int i = a[0]; i <= a[2]; i++)
                for (int j = a[1]; j <= a[3]; j++)
                    grid[i][j] = id, tot++;
            cnt[id] = tot;
            id++;
        }
        int ans = 0;
        for (auto &d : dig) {
            int i = d[0];
            int j = d[1];
            if (!grid[i][j]) continue;
            int cur_id = grid[i][j];
            if (--cnt[cur_id] == 0) ans++;
            grid[i][j] = 0;
        }
        return ans;
    }
};