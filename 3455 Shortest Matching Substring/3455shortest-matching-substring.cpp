class Solution {
public:
    vector<int> z_function(string &s) {
        int n = s.size();
        vector<int> z(n);
        for (int i = 1, l = 0, r = 0; i < n; i++) {
            if (i <= r) z[i] = min(z[i - l], r - i + 1);
            while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
            if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
        }
        return z;
    }
    int find(int i, vector<vector<int>> &idx, vector<string> &ss, int last_idx) {
        if (i == idx.size()) return ss[i - 1].size();
        auto it = lower_bound(idx[i].begin(), idx[i].end(), last_idx + ss[i - 1].size());
        if (it == idx[i].end()) return INT_MAX;
        int next_idx = idx[i][it - idx[i].begin()];
        int res = find(i + 1, idx, ss, next_idx);
        if (res == INT_MAX) return INT_MAX;
        return next_idx - last_idx + res;
    }
    int shortestMatchingSubstring(string s, string p) {
        int len_s = s.size(), len_p = p.size();
        int i = 0;
        vector<string> ss;
        while (i < len_p) {
            if (p[i] == '*') {
                i++; continue;
            }
            string cur = "";
            while (i < len_p && p[i] != '*') {
                cur += p[i++];
            }
            ss.push_back(cur);
        }
        if (!ss.size()) return 0;
        vector<vector<int>> idx(ss.size(), vector<int>());
        i = 0;
        for (auto &t : ss) {
            string u = t + '#' + s;
            int len_t = t.size();
            auto z = z_function(u);
            for (int j = len_t + 1; j < z.size(); j++) {
                if (z[j] == len_t) {
                    idx[i].push_back(j - (len_t + 1));
                }
            }
            i++;
        }
        if (idx.size() == 1) {
            if (!idx[0].size()) return -1;
            return ss[0].size();
        }
        int ans = INT_MAX;
        for (int i = 0; i < idx[0].size(); i++) {
            ans = min(ans, find(1, idx, ss, idx[0][i]));
        }
        return ans == INT_MAX ? -1 : ans;
    }
};