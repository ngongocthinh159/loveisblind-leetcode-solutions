class Solution {
public:
    string makeFancyString(string s) {
        string res = "";
        int i = 0, n = s.size();
        while (i < n) {
            char c = s[i];
            int st = i, e = i;
            while (i < n && s[i] == c) {
                e = i;
                i++;
            }
            int len = min(2, e - st + 1);
            while (len--) res += c;
        }
        return res;
    }
};