class Solution {
public:
    bool halvesAreAlike(string s) {
        unordered_set<char> vow = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int cnt1 = 0;
        int cnt2 = 0;
        int n = s.size();
        for (int i = 0; i < n/2; i++) {
            if (vow.count(s[i])) cnt1++;
        }
        for (int i = n/2; i < n; i++) {
            if (vow.count(s[i])) cnt2++;
        }
        return cnt1 == cnt2;
    }
};