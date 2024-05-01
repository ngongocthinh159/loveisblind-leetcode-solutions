class Solution {
public:
    string reversePrefix(string word, char ch) {
       int r = -1;
       for (int i = 0; i < word.size(); i++) if (word[i] == ch) {
            r = i; break;
       }
        if (r != -1) reverse(word.begin(), word.begin() + r + 1);
        return word;
    }
};