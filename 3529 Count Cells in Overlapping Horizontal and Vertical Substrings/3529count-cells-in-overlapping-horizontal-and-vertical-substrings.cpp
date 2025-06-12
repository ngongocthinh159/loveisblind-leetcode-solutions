class Solution {
public:
    vector<int> z_func(string &s) {
        int n = s.size();
        vector<int> z(n);
        for (int i = 1, l = 0, r = 0; i < n; i++) {
            if (i <= r) z[i] = min(r - i + 1, z[i - l]);
            while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
            if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
        }
        return z;
    }
    int countCells(vector<vector<char>>& grid, string pattern) {
        int n = grid.size(), m = grid[0].size();
        string s1 = "", s2 = "";
        vector<int> ok1(n*m + 1), ok2(n*m + 1);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) s1 += grid[i][j];
        for (int j = 0; j < m; j++)
            for (int i = 0; i < n; i++) s2 += grid[i][j];
        string t1 = pattern + "#" + s1;
        string t2 = pattern + "#" + s2;
        auto z1 = z_func(t1);
        auto z2 = z_func(t2);
        for (int i = pattern.size() + 1; i < (int) t1.size(); i++) {
            if (z1[i] >= (int) pattern.size()) {
                int j = i - (int) pattern.size() - 1;
                ok1[j]++;
                ok1[j + pattern.size()] -= 1;
            }
            if (z2[i] >= (int) pattern.size()) {
                int j = i - (int) pattern.size() - 1;
                ok2[j]++;
                ok2[j + pattern.size()] -= 1; 
            }
        }
        for (int i = 0; i < n*m; i++) ok1[i + 1] += ok1[i], ok2[i + 1] += ok2[i];
        int cnt = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                int idx1 = m*i + j;
                int idx2 = n*j + i;
                if (ok1[idx1] >= 1 && ok2[idx2] >= 1) {
                    cnt++;
                }
            }
        return cnt;
    }
};