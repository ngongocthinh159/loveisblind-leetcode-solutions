class Solution {
public:
    unordered_set<char> v = {'a', 'e', 'i', 'o', 'u'};
    int maxFreqSum(string s) {
        int c1[26]{};
        int c2[26]{};
        int mx1 = 0, mx2 = 0;
        for (auto c : s) {
            if (v.count(c)) mx1 = max(mx1, ++c1[c - 'a']);
            else mx2 = max(mx2, ++c2[c - 'a']);
        }
        return mx1 + mx2;
    }
};