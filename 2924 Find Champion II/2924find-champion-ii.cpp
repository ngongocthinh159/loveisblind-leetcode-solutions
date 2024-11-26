class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> indeg(n);
        for (auto &e : edges) indeg[e[1]]++;
        int cnt = 0, ver;
        for (int i = 0; i < n; i++) {
            if (indeg[i] == 0) cnt++, ver = i;
        }
        if (cnt == 1) return ver;
        return -1;
    }
};