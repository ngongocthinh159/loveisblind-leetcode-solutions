class Solution {
public:
    // https://leetcode.com/problems/last-substring-in-lexicographical-order/solutions/363662/short-python-code-o-n-time-and-o-1-space-with-proof-and-visualization/
    string lastSubstring(string s) {
        int n = s.size();
        int i = 0, j = 1, k = 0;
        while (j + k < n) {
            if (s[i + k] == s[j + k]) {
                k++;
            } else if (s[i + k] < s[j + k]) {
                i = max(i + k + 1, j);
                j = i + 1;
                k = 0;
            } else {
                j = j + k + 1;
                k = 0;
            }
        }
        return s.substr(i);
    }
};