class Solution {
public:
    int takeCharacters(string s, int k) {
        if (k == 0) return 0;
        vector<int> cnt(3);
        for (auto c : s) cnt[c - 'a']++;
        for (auto x : cnt) if (x < k) return -1;
        int n = s.size();
        int r = n - 1;
        int l = n - 1;
        s += s;
        vector<int> freq(3);
        int ok = 0;
        freq[s[r] - 'a']++;
        if (freq[s[r] - 'a'] == k) ok++;
        while (ok < 3) {
            l--;
            freq[s[l] - 'a']++;
            if (freq[s[l] - 'a'] == k) ok++;
        }
        int ans = r - l + 1;
        r++;
        while (r < 2*n) {
            freq[s[r] - 'a']++;
            if (freq[s[r] - 'a'] == k) ok++;

            while (l <= n && ok == 3) {
                ans = min(ans, r - l + 1);
                freq[s[l] - 'a']--;
                if (freq[s[l] - 'a'] == k - 1) ok--;
                l++;
            }

            r++;
        }
        return ans;
    }
};