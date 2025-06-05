class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string res = "";
        int i = 0, j = 0, n = word1.size(), m = word2.size();
        bool turn = 0;
        while (i < n && j < m) {
            if (!turn)
                res += word1[i++];
            else
                res += word2[j++];
            turn = turn ^ 1;
        }
        while (i < n) res += word1[i++];
        while (j < m) res += word2[j++];
        return res;
    }
};