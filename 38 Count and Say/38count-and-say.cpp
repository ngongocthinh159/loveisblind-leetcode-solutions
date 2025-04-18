class Solution {
public:
    string RLE(string &s) {
        string res = "";
        int n = s.size(), i = 0;
        while (i < n) {
            char c = s[i];
            int cnt = 0;
            while (i < n && s[i] == c) {
                cnt++;
                i++;
            }
            res += to_string(cnt);
            res += c;
        }
        return res;
    }
    string countAndSay(int n) {
        string cur = "1";
        for (int i = 0; i < n - 1; i++) {
            cur = RLE(cur);
        }
        return cur;
    }
};