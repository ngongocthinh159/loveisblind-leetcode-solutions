class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        string res = dominoes;
        deque<int> q;
        vector<bool> vis(n);
        for (int i = 0; i < n; i++) if (res[i] != '.') {
            q.push_front(i);
            vis[i] = true;
        }
        while (q.size()) {
            int sz = q.size();
            unordered_map<int,pair<bool,bool>> M;
            while (sz--) {
                int u = q.back(); q.pop_back();
                if (res[u] == 'L' && u - 1 >= 0 && !vis[u - 1]) {
                    M[u - 1].first = true;
                }
                if (res[u] == 'R' && u + 1 < n && !vis[u + 1]) {
                    M[u + 1].second = true;
                }
            }
            for (auto &[u, p] : M) {
                vis[u] = true;
                if (p.first && p.second) continue;
                if (p.first) res[u] = 'L';
                if (p.second) res[u] = 'R';
                q.push_front(u);
            }
        }
        return res;
    }
};