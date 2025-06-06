class Solution {
public:
    string onlyAlphaNumbericAndLowerCase(string &s) {
        string t = "";
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if ('A' <= s[i] && s[i] <= 'Z') {
                t += s[i] - 'A' + 'a';
            } 
            if (('a' <= s[i] && s[i] <= 'z') || 
                '0' <= s[i] && s[i] <= '9') {
                t += s[i];
            }
        }
        return t;
    }
    bool isPalindrome(string s) {
        string t = onlyAlphaNumbericAndLowerCase(s);
        int n = t.size();
        for (int i = 0, j = n - 1; i < j; i++, j--) {
            if (t[i] != t[j]) return false;
        }
        return true;
    }
};