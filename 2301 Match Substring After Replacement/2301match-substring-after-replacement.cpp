class Solution {
public:
    int get_idx(char c) {
        if (c == '#') return 62;
        if ('a' <= c && c <= 'z') return c - 'a';
        if ('A' <= c && c <= 'Z') return c - 'A' + 26;
        if ('0' <= c && c <= '9') return c - '0' + 52;
        return -1;
    }
    bool ok(int c, int target_c, vector<unordered_set<int>> &g) {
        int idx = get_idx(c);
        int target_idx = get_idx(target_c);
        if (idx == target_idx) return true;
        return g[idx].count(target_idx);
    }
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
        int n = s.size(), m = sub.size();
        vector<unordered_set<int>> g(62);
        for (auto &m : mappings) {
            g[get_idx(m[0])].insert(get_idx(m[1]));
        }
        for (int r = m - 1; r < n; r++) {
            bool _ok = true;
            for (int j = r - m + 1, k = 0; j <= r; j++, k++) if (!ok(sub[k], s[j], g)) {
                _ok = false;
                break;
            }
            if (_ok) return true;
        }
        return false;
    }
};