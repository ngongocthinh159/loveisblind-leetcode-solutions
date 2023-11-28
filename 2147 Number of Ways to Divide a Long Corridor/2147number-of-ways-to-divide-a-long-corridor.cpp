class Solution {
public:
    int MOD = 1e9 + 7;
    int numberOfWays(string corridor) {
        int i = 0, cnt = 0, s = 0, p = 0, res = 1;
        while (i < corridor.size()) {
            if (corridor[i] == 'S') s++;

            if (cnt < 2) {
                if (corridor[i] == 'S') cnt++;
            } else {
                if (corridor[i] == 'P') p++;
                else {
                    if (p != 0) res = ((long long) res * (p + 1)) % MOD;
                    cnt = 1;
                    p = 0;
                }
            }
            
            i++;
        }
        if (s < 2 || s % 2 != 0) return 0;
        return res;
    }
};