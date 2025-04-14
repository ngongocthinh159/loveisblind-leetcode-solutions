class Solution {
public:
   
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> prf(n, vector<int>(m + 1));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) prf[i][j + 1] = prf[i][j] + matrix[i][j];
        int ans = -(1e9 + 5);
        for (int l = 0; l < m; l++)
            for (int r = l; r < m; r++) {
                vector<int> pref(n + 1);
                set<int> S;
                S.insert(0);
                for (int i = 0; i < n; i++) {
                    pref[i + 1] = pref[i] + (prf[i][r + 1] - prf[i][l]);
                    auto it = S.lower_bound(pref[i + 1] - k);
                    if (it != S.end())
                        ans = max(ans, pref[i + 1] - *it);
                    S.insert(pref[i + 1]);
                }
            }
        return ans;
    }
};