class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<bool> ok1(26);
        vector<bool> ok2(26);
        for (auto c : word) {
            if ('a' <= c && c <= 'z') ok1[c-'a'] = true;
            else ok2[c-'A'] = true;
        }
        int cnt = 0;
        for (int i = 0; i < 26; i++) {
            if (ok1[i] && ok2[i]) cnt++;
        }
        return cnt;
    }
};