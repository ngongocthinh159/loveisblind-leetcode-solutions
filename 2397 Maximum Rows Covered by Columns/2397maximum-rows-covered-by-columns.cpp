class Solution {
public:
    int maximumRows(vector<vector<int>>& matrix, int numSelect) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) if (matrix[i][j]) a[i] ^= (1 << j);
        int mMask = (1 << m) - 1, ans = 0;
        for (int mask = 1; mask <= mMask; mask++) {
            if (__builtin_popcount(mask) != numSelect) continue;
            int cnt = 0;
            for (int i = 0; i < n; i++) if ((a[i] & mask) == a[i]) cnt++;
            ans = max(ans, cnt);
        }
        return ans;
    }
};