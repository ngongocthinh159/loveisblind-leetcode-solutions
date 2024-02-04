class Solution {
public:
    int numSubmatrixSumTarget(std::vector<std::vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + matrix[i - 1][j - 1];
            }
        }
        int cnt = 0;
        unordered_map<int,int> mp;
        mp.reserve(1e4);
        for (int x1 = 0; x1 < n; x1++) {
            for (int x2 = x1; x2 < n; x2++) {
                mp.clear();
                mp[0]++;
                for (int y1 = 0; y1 < m; y1++) {
                    int cur = pref[x2 + 1][y1 + 1] - pref[x1][y1 + 1];
                    cnt += mp[cur - target];
                    mp[cur]++;
                }   
            }
        }
        return cnt;
    }
};
