class Solution {
public:
    int maxVowels(string s, int k) {
        unordered_set<char> S = {'a', 'e', 'i', 'o', 'u'};
        int cnt = 0;
        for (int r = 0; r < k; r++) {
            if (S.count(s[r])) cnt++;
        }
        int ans = cnt;
        for (int r = k; r < s.size(); r++) {
            if (S.count(s[r])) cnt++;
            int l = r - k;
            if (S.count(s[l])) cnt--;
            ans = max(ans, cnt);
        }
        return ans;
    }
};