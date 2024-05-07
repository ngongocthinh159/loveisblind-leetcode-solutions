class Solution {
public:
    bool has_edge(string &s1, string &s2) {
        int cnt = 0;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) {
                cnt++;
                if (cnt >= 2) return false;
            }
        }
        return true;
    }
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        bank.push_back(startGene);
        int n = bank.size();
        unordered_map<string, unordered_set<string>> g;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (has_edge(bank[i], bank[j])) {
                    g[bank[i]].insert(bank[j]);
                    g[bank[j]].insert(bank[i]);
                }
            }
        }
        deque<string> q;
        q.push_front(startGene);
        unordered_set<string> visited;
        int level = 0;
        while (q.size()) {
            int size = q.size();
            for (int k = 0; k < size; k++) {
                auto u = q.back(); q.pop_back();
                if (u == endGene) return level;
                for (auto &v : g[u]) {
                    if (!visited.count(v)) {
                        visited.insert(v);
                        q.push_front(v);
                    }
                }
            }
            level++;
        }
        return -1;
    }
};