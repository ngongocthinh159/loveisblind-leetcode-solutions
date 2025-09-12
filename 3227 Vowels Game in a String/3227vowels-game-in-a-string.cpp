class Solution {
public:
    unordered_set<char> vow = {'a', 'e', 'i', 'o', 'u'};
    bool doesAliceWin(string s) {
        int cnt = 0;
        for (auto c : s) if (vow.count(c)) cnt++;
        if (cnt == 0) return false;
        return true;
    }
};