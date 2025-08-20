class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0) return false;
        return (n & (n - 1)) == 0 && (32 - __builtin_clz(n) - 1) % 2 == 0;
    }
};