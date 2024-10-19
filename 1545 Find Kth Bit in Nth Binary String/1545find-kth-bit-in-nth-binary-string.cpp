class Solution {
public:
    char findKthBit(int n, int k) {
        vector<int> lenS(n + 1);
        lenS[1] = 1;
        for (int i = 2; i <= n; i++) {
            lenS[i] = 2*lenS[i - 1] + 1;
        }
        bool rv = false;
        while (n != 1) {
            
            int tmp = lenS[n - 1] + 1;
            if (k == tmp) {
                return rv ? '0' : '1';
            } else if (k > tmp) {
                k -= tmp;
                rv = true;
            } else {
                rv = false;
            }

            n -= 1;
        }
        return rv ? '1' : '0';
    }
};