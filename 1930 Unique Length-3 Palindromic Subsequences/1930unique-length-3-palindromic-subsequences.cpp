class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        vector<vector<int>> freq(n, vector<int>(26));
        vector<pair<int,int>> seen(26, {-1, -1});
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 26; j++) {
                freq[i][j] = (i == 0 ? 0 : freq[i - 1][j]) + ((s[i] - 'a') == j);
            }
            if (seen[s[i] - 'a'].first == -1) seen[s[i] - 'a'].first = i;
            else seen[s[i] - 'a'].second = i;
        }
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            if (seen[i].first == -1 || seen[i].second == -1) continue;
            int l = seen[i].first + 1;
            int r = seen[i].second - 1;
            if (l > r) continue;
            for (int j = 0; j < 26; j++) {
                if (freq[r][j] - freq[l - 1][j] >= 1) ans++;
            }
        }
        return ans;
    }
};