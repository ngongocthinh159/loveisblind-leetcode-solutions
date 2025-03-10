class Solution {
public:
    long long helper(string &word, int k) {
        vector<bool> vowel(26);
        for (char c : {'a', 'e', 'i', 'o', 'u'}) vowel[c - 'a'] = true;
        vector<int> freq(26);
        int unique = 0, vowel_cnt = 0, l = 0, n = word.size();
        bool found = false;
        long long ans = 0;
        for (int r = 0; r < n; r++) {
            freq[word[r] - 'a']++;
            if (vowel[word[r] - 'a']) {
                vowel_cnt++;
                if (freq[word[r] - 'a'] == 1) unique++;
            }
            
            while (l < r && unique == 5 && (r - l + 1 - vowel_cnt) >= k) {
                found = true;
                freq[word[l] - 'a']--;
                if (vowel[word[l] - 'a']) {
                    vowel_cnt--;
                    if (freq[word[l] - 'a'] == 0) unique--;
                }
                l++;
            }

            if (found) {
                ans += l;
            }
        }
        return ans;
    }
    long long countOfSubstrings(string word, int k) {
        return helper(word, k) - helper(word, k + 1); 
    }
};