class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        int n = numCourses;
        vector<vector<vector<int>>> dist(n + 1,
            vector<vector<int>>(n,
                vector<int>(n, INT_MAX)));
        for (int i = 0; i < n; i++) dist[0][i][i] = 0;
        for (auto &p : prerequisites) dist[0][p[0]][p[1]] = 1;
        for (int k = 1; k <= n; k++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++) {
                    dist[k][i][j] = dist[k - 1][i][j];
                    if (dist[k - 1][i][k - 1] != INT_MAX && dist[k - 1][k - 1][j] != INT_MAX)
                        dist[k][i][j] = min(dist[k][i][j], dist[k - 1][i][k - 1] + dist[k - 1][k - 1][j]);
                }
        vector<bool> ans;
        for (auto &q : queries) {
            ans.push_back(dist[n][q[0]][q[1]] != INT_MAX ? true : false);
        }
        return ans;
    }
};