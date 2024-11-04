class Solution {
public:
    string compressedString(string word) {
        int i = 0;
        string res = "";
        while (i < word.size()) {
            int l = i, r;
            char c = word[i];
            int cnt = 0;
            while (i < word.size() && word[i] == c && cnt < 9) {
                r = i;
                cnt++;
                i++;
            }
            res += (r - l + 1) + '0';
            res += c;
        }
        return res;
    }
};