class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> cnt(52, 0);
        for (auto c : s) {
            cnt[(c <= 'Z') ? (c - 'A') : (c - 'a' + 26)]++;
        }
        int mx_odd = 0;
        int even = 0;
        for (auto i : cnt) {
            even += i;
            if (i&1) {
                mx_odd = max(mx_odd, i);
                even -= 1;
            }
        }
        if (mx_odd != 0) even -= (mx_odd - 1);
        return even + mx_odd;
    }
};