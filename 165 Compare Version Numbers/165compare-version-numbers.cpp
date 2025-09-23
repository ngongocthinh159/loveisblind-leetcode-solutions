class Solution {
public:
    vector<unsigned int> sep(string &s) {
        vector<unsigned int> res;
        int i = 0, n = s.size();
        while (s[i] == '0') i++;
        while (i < n) {
            unsigned int cur = 0;
            while (i < n && s[i] != '.') cur = 10 * cur + s[i] - '0', i++;
            res.push_back(cur);
            i++;
        }
        if (!res.size()) res.push_back(0);
        return res;
    }
    int compareVersion(string version1, string version2) {
        auto t1 = sep(version1);
        auto t2 = sep(version2);
        int i = 0, j = 0;
        int n = t1.size(), m = t2.size();
        while (i < n && j < m) {
            if (t1[i] > t2[j]) return 1;
            if (t1[i] < t2[j]) return -1;
            i++, j++;
        }
        while (i < n) {
            if (t1[i] != 0) return 1;
            i++;
        }
        while (j < m) {
            if (t2[j] != 0) return -1;
            j++;
        }
        return 0;
    }
};