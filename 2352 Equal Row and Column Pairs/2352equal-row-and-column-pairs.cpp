#define ll long long
class Solution {
public:
    const int m = 1e9 + 7;
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        int ans = 0;
        vector<int> row(n);
        vector<int> col(n);
        ll base = 1e5 + 1;
        vector<int> basePow(n + 1);
        basePow[0] = 1;
        for (int i = 1; i <= n; i++) {
            basePow[i] = (basePow[i - 1]*base)%m;
        }
        for (int i = 0; i < n; i++) {
            ll hash = 0;
            for (int j = 0; j < n; j++) {
                hash = (hash + (1LL*grid[i][j]*basePow[j])%m) % m;
            }
            row[i] = hash;
        }
        for (int j = 0; j < n; j++) {
            ll hash = 0;
            for (int i = 0; i < n; i++) {
                hash = (hash + (1LL*grid[i][j]*basePow[i])%m) % m;
            }
            col[j] = hash;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (row[i] == col[j]) ans++;
            }
        }
        return ans;
    }
};