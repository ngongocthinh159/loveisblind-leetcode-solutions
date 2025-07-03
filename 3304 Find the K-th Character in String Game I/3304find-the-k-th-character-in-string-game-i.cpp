class Solution {
public:
    char kthCharacter(int k) {
        int msb = 32 - __builtin_clz(k) - 1;
        int oper = 0;
        if ((k & (k - 1)) == 0)
            oper = msb;
        else
            oper = msb + 1;
        long long cur = (1LL << oper);
        int cnt = 0;
        while (cur != 1) {
            long long half = (cur >> 1);
            if (k > half) {
                cnt++;
                k -= half;
            }
            cur -= half;
        }
        return cnt % 26 + 'a';
    }
};