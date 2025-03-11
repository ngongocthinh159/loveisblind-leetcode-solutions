class Solution {
public:
    int numberOfSubstrings(string s) {
        int cnt[3];
        int l = 0, unique = 0, ans = 0;
        bool found = false;
        for (int r = 0 ; r < s.size(); r++) {
            if (++cnt[s[r] - 'a'] == 1) unique++;
            while (l <= r && unique == 3) {
                found = true;
                if (--cnt[s[l] - 'a'] == 0) unique--;
                l++;
            }
            if (found) {
                ans += l;
            }
        }
        return ans;
    }
};