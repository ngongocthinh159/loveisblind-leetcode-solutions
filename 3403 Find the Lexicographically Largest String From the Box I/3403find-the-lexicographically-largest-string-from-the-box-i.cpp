class Solution {
public:
    int largestSuffixIdx(string &s) {
        int i = 0, j = 1, k = 0, n = s.size();
        while (j + k < n) {
            if (s[i + k] == s[j + k])
                k++;
            else if (s[i + k] > s[j + k]) {
                j = j + k + 1;
                k = 0;
            } else {
                i = max(i + k + 1, j);
                j = i + 1;
                k = 0;
            }
        }
        return i;
    }
    string answerString(string word, int numFriends) {
        int n = word.size();
        if (numFriends == 1)
            return word;
        int idx = largestSuffixIdx(word);
        return word.substr(idx, min(n - idx, n - numFriends + 1));
    }
};