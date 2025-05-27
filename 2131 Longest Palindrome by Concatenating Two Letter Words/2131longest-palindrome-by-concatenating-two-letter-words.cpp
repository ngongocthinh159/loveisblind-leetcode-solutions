class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int freq[26][26]{};
        for (auto &w : words) {
            freq[w[0] - 'a'][w[1] - 'a']++;
        }
        bool hasOdd = false;
        int ans = 0;
        for (int i = 0; i < 26; i++)
            for (int j = 0; j < 26; j++) {
                if (i == j) {
                    if (freq[i][j]&1) hasOdd = true;
                    ans += freq[i][j]/2 * 2 * 2;
                } else {
                    ans += min(freq[i][j], freq[j][i]) * 2 * 2;
                    freq[i][j] = freq[j][i] = 0;
                }
            }
        if (hasOdd) ans += 2;
        return ans;
    }
};