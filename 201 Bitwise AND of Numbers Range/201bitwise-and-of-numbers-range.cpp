class Solution {
public:
    int rangeBitwiseAnd(int l, int r) {
        int shift = 0;
        while (l != r && l > 0) {
            l >>= 1; r >>= 1; shift++;
        }
        return l << shift;
    }
};