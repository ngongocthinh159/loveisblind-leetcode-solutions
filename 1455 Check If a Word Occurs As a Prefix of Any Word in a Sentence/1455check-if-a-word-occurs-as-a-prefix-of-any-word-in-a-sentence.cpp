class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int i = 0, j = 0;
        int n = sentence.size();
        int m = searchWord.size();
        int idx = 0;
        while (i < n && j < m) {
            while (i < n && j < m && sentence[i] == searchWord[j]) {
                i++; j++;
            }
            if (j == m) return idx + 1;
            while (i < n && sentence[i] != ' ') i++;
            i++;
            idx++;
            j = 0;
        }
        return -1;
    }
};