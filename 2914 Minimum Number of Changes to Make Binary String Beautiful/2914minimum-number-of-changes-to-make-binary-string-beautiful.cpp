class Solution {
public:
    int minChanges(string s) {
        int res = 0;
        for (int i = 1; i < s.size(); i+=2) {
            res += (s[i] - '0')^(s[i - 1] - '0');
        }
        return res;
    }
};