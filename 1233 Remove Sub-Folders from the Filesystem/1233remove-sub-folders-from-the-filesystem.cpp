class Solution {
public:
    bool startwith(const vector<string> &s, const vector<string> &p) {
        int n = s.size(), m = p.size();
        int i = 0, j = 0;
        while (i < n && j < m && s[i] == p[j]) i++, j++;
        return j == m;
    }
    vector<string> toFolders(string &s) {
        vector<string> res;
        int i = 0, n = s.size();
        while (i < n) {
            i++;
            string cur = "";
            while (i < n && s[i] != '/') {
                cur += s[i++];
            }
            res.push_back(cur);
        }
        return res;
    }
    vector<string> removeSubfolders(vector<string>& f) {
        int n = f.size();
        sort(f.begin(), f.end());
        vector<string> res;
        for (int i = 0; i < n; ) {
            string pref = f[i];
            auto folders = toFolders(pref);
            while (i < n && startwith(toFolders(f[i]), folders)) {
                i++;
            }
            res.push_back(pref);
        }
        return res;
    }
};