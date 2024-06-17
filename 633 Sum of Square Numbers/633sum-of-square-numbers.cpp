class Solution {
public:
    bool judgeSquareSum(int c) {
        int b_square, b_sqrt;
        for (int a = 0; a <= sqrt(c); a++) {
            b_square = c - a*a;
            b_sqrt = sqrt(b_square);
            if (b_sqrt*b_sqrt == b_square) return true;
        }
        return false;
    }
};