class Solution {
public:
    // proof: https://leetcode.com/problems/minimum-operations-to-make-the-integer-zero/solutions/7157889/why-60-actually-37-completed-proof-it-took-me-2hrs/
    int makeTheIntegerZero(int num1, int num2) {
        for (int ops = 1; ops <= 36; ops++) {
            long long remain = num1 - 1LL * num2 * ops;
            if (remain > 0) {
                if (__builtin_popcountll(remain) <= ops && ops <= remain)
                    return ops;
            } else
                break;
        }
        return -1;
    }
};