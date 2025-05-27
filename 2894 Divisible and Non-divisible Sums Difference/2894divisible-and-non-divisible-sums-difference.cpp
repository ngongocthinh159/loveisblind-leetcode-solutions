class Solution {
public:
    long long sumDivide(int n, int x) {
        if (n < x) return 0;
        int last = n/x;
        return 1LL * x * (last + 1) * last / 2;
    }
    int differenceOfSums(int n, int m) {
        return 1LL * (n + 1) * n / 2 - 1LL * 2 * sumDivide(n, m);
    }
};