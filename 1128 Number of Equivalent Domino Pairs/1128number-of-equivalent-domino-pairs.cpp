class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& d) {
        int cnt[10][10]{};
        int n = d.size();
        for (int i = 0; i < n; i++) {
            int a = d[i][0], b = d[i][1];
            if (a > b) swap(a, b);
            cnt[a][b]++;
        }
        int ans = 0;
        for (int i = 1; i <= 9; i++)
            for (int j = 1; j <= 9; j++) if (cnt[i][j]) {
                ans += cnt[i][j] * (cnt[i][j] - 1) / 2;
            }
        return ans;
    }
};