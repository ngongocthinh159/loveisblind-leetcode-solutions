class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        bool b[26]{};
        for (auto c : brokenLetters) b[c - 'a'] = 1;
        int i = 0, n = text.size(), ans = 0;
        while (i < n) {
            while (i < n && text[i] == ' ') i++;
            int len = 0;
            bool f = false;
            while (i < n && text[i] != ' ') {
                if (b[text[i] - 'a']) f = true;
                i++, len++;
            }
            if (len && !f) ans++;
        }
        return ans;
    }
};