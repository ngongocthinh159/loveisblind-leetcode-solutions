class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        string tmp = s;
        for (int i = 1; i < s.size(); i++) {
            tmp += s[i - 1];
            if (tmp.substr(i, n) == s) return true;
        }
        return false;
    }
};