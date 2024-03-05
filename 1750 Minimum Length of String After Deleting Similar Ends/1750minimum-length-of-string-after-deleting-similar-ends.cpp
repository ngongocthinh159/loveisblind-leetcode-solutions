class Solution {
public:
    int minimumLength(string s) {
        int i = 0, j = s.size() - 1;
        int cnt;
        while (i <= j) {
            if (s[i] != s[j]) return j - i + 1;
            char c = s[i];
            cnt = 0;
            while (i <= j && c == s[i]) {cnt++;i++;}
            while (i <= j && c == s[j]) j--;
        }
        return cnt==1?1:0;
    }
};