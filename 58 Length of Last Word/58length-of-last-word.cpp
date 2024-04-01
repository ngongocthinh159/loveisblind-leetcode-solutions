class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = 0;
        string word = "";
        while (i < s.size()) {
            if (s[i] != ' ') {
                string cur(1, s[i]);
                while (i + 1 < s.size() && s[i + 1] != ' ') {
                    cur += s[i + 1];
                    i++;
                }
                word = cur;
            }
            i++;
        }
        return word.size();
    }
};