class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        string t = to_string(num);
        int n = s.size();
        char c1 = s[0], c2 = t[0];
        for (int i = 0; i < n;) {
            if (s[i] != '9') {
                char c = s[i];
                while (i < n) {
                    if (s[i] == c) s[i] = '9';
                    i++;
                }
                break;
            } else
                i++;
        }
        for (int i = 0; i < n; i++) {
            if (t[i] != '0') {
                char c = t[i];
                while (i < n) {
                    if (t[i] == c) t[i] = '0';
                    i++;
                }
                break;
            } else {
                i++;
            }
        }
        int mx = 0, mn = 0;
        int idx = 0;
        while (idx < n && t[idx] == '0') idx++;
        t = t.substr(idx);
        cout << s << ' ' << t << '\n';
        for (int i = 0; i < s.size(); i++) mx = 10*mx + (s[i] - '0');
        for (int i = 0; i < t.size(); i++) mn = 10*mn + (t[i] - '0');
        return mx - mn;
    }
};