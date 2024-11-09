class Solution {
public:
    long long minEnd(int n, int x) {
        if (n == 1) return x;
        n--;
        long long res = x;
        for (int bit = 0; bit <= 63; bit++) {
            if (!((res >> bit) & 1)) {
                res = res | (1LL*(n & 1) << bit);
                n >>= 1;
            }
        }
        return res;
    }
};