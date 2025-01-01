class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        if (dividend == 0) return 0;
        int neg = 2;
        if (dividend >= 0) {
            neg--;
            dividend = -dividend;
        }
        if (divisor >= 0) {
            neg--;
            divisor = -divisor;
        }
        int q = 0;

        int msb = -1;
        int cur = 0;
        while ((cur >= INT_MIN - cur) && ((msb == -1 ? divisor : (cur + cur)) >= dividend)) {
            cur = (msb == -1 ? divisor : cur + cur);
            msb++;
        }

        for (int bit = msb; bit >= 0; bit--) {
            if (dividend - cur <= 0) {
                dividend -= cur;
                q += (-1 << bit);
            }
            cur = (cur + 1) >> 1;
        }

        if (neg != 1) q = -q;
        return q;
    }
};