class Solution {
public:
    unordered_map<string,int> wToId;
    unordered_map<int,string> idToW;
    vector<vector<int>> g;
    vector<vector<string>> res;
    vector<int> path;
    vector<int> dist;
    int id = 0;
    const int IINF = 1e9;
    int diff(string &s, string &t) {
        int res = 0;
        for (int i = 0; i < s.size(); i++) if (s[i] != t[i]) res++;
        return res;
    }
    void bfs(int src) {
        dist.assign(id, IINF);
        dist[src] = 0;
        deque<int> q;
        q.push_front(src);
        while (q.size()) {
            int sz = q.size();
            while (sz--) {
                int u = q.back(); q.pop_back();
                for (auto v : g[u]) if (dist[v] == IINF) {
                    dist[v] = dist[u] + 1;
                    q.push_front(v);
                }
            }
        }
    }
    void dfs(int u, int p, int cur_dist) {
        path.push_back(u);
        if (u == 0) {
            vector<string> cur;
            for (int i = (int) path.size() - 1; i >= 0; i--) {
                cur.push_back(idToW[path[i]]);
            }
            res.emplace_back(cur);
            path.pop_back();
            return;
        }
        for (auto v : g[u]) if (v != p) {
            if (cur_dist + 1 + dist[v] == dist[id - 1]) {
                dfs(v, u, cur_dist + 1);
            }
        }
        path.pop_back();
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        idToW[id] = beginWord;
        wToId[beginWord] = id++;
        bool found = false;
        for (auto &w : wordList) {
            if (w == beginWord) continue;
            if (w == endWord) {
                found = true;
                continue;
            }
            idToW[id] = w;
            wToId[w] = id++;
        }
        if (!found) return vector<vector<string>>();
        idToW[id] = endWord;
        wToId[endWord] = id++;
        g.resize(id);
        for (int i = 0; i < id; i++)
            for (int j = 0; j < i; j++) {
                if (diff(idToW[i], idToW[j]) == 1) {
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        bfs(0);
        if (dist[id - 1] == IINF) return vector<vector<string>>();
        dfs(id - 1, -1, 0);
        return res;
    }
};