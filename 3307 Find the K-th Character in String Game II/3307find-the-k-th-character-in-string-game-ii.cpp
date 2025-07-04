class Solution {
public:
    char find(long long k, long long n, vector<int> &opers, long long plus, int j) {
        if (n == 1) return plus%26 + 'a';
        long long half = n/2;
        if (k > half) return find(k - half, n/2, opers, plus + opers[j], j - 1);
        return find(k, n/2, opers, plus, j - 1);
    }
    char kthCharacter(long long k, vector<int>& operations) {
        int msb = 64 - __builtin_clzll(k) - 1;
        msb++;
        long long n = (1LL << msb);
        return find(k, n, operations, 0, msb - 1);
    }
};