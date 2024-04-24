class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};
        if (n == 2) return {0,1};
        vector<vector<int>> g(n);
        vector<int> inDeg(n);
        for (auto &e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
            inDeg[e[0]]++;
            inDeg[e[1]]++;
        }
        deque<int> q;
        for (int i = 0; i < n; i++) {
            if (inDeg[i] == 1) q.push_back(i);
        }
        while (n > 2) {
            int size = q.size();
            n -= size;
            for (int i = 0; i < size; i++) {
                int u = q.back(); q.pop_back();
                inDeg[u] = -1;
                for (auto &v : g[u]) {
                    inDeg[v]--;
                    if (inDeg[v] == 1) {
                        q.push_front(v);
                    }
                }
            }
        }
        vector<int> res;
        while (q.size()) {
            res.push_back(q.back()); q.pop_back();
        }
        return res;
    }
};