class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>> cityToRoads(n);
        int roadSz = roads.size();
        vector<unordered_map<int,int>> freq(n, unordered_map<int,int>());
        vector<int> deg(n);
        for (int i = 0; i < roadSz; i++) {
            int u = roads[i][0];
            int v = roads[i][1];
            if (u > v) swap(u,v);
            freq[u][v]++;
            deg[u]++;
            deg[v]++;
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) if (i != j) {
                int f = i < j ? freq[i][j] : freq[j][i];
                ans = max(ans, deg[i] + deg[j] - f);
            }
        }
        return ans;
    }
};