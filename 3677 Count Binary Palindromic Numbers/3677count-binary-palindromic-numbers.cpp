#define ll long long
class Solution {
public:
    int cal(int len) {
        int res = 1;
        for (int i = 1; i <= len; i++) res += pow(2, (i + 1)/2 - 1);
        return res;
    }
    int countBinaryPalindromes(long long n) {
        string s = "";
        long long tmp = n;
        while (tmp) {
            if (tmp&1) s += '1';
            else s += '0';
            tmp >>= 1;
        }
        reverse(s.begin(), s.end());
        int len = s.size();
        int half = (len + 1) / 2;
        int cur = 0;
        for (int i = 1; i < half; i++) if (s[i] == '1') {
            cur += pow(2, half - i - 1);
        }
        for (int i = 0, j = len - 1; i < j; i++, j--) s[j] = s[i];
        long long x = 0;
        for (int bit = 0; bit < len; bit++) {
            if (s[len - 1 - bit] == '1') x |= (1LL << bit);
        }
        return cur + (x <= n && x != 0) + cal(len - 1);
    }
};