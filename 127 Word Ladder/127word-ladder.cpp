class Solution {
public:
    bool check(string &s, string &t) {
        int cnt = 0;
        for (int i = 0; i < s.size(); i++) if (s[i] != t[i]) {
            cnt++;
            if (cnt >= 2) return false;
        }
        return cnt == 1;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,int> wToId;
        unordered_map<int,string> idToW;
        int id = 0;
        wToId[beginWord] = id;
        idToW[id++] = beginWord;
        for (auto &w : wordList) {
            if (wToId.count(w)) continue;
            wToId[w] = id;
            idToW[id++] = w;
        }
        if (!wToId.count(endWord)) return 0;
        int src = 0, dst = wToId[endWord];
        vector<vector<int>> g(id);
        for (int i = 0; i < id; i++)
            for (int j = 0; j < id; j++) if (i != j && check(idToW[i], idToW[j])) {
                g[i].push_back(j);
                g[j].push_back(i);
            }
        vector<int> dist(id, 1e9);
        dist[0] = 0;
        deque<int> q;
        q.push_front(0);
        while (q.size()) {
            for (int sz = q.size(); sz; sz--) {
                auto u = q.back();
                q.pop_back();
                // for (int v = 0; v < id; v++) if (dist[v] > dist[u] + 1 && check(idToW[u], idToW[v])) {
                //     dist[v] = dist[u] + 1;
                //     q.push_front(v);
                //     if (v == dst)
                //         return dist[v] + 1;
                // }
                for (auto v : g[u]) if (dist[v] > dist[u] + 1) {
                    dist[v] = dist[u] + 1;
                    q.push_front(v);
                    if (v == dst)
                        return dist[v] + 1;
                }
            }
        }
        return 0;
    }
};