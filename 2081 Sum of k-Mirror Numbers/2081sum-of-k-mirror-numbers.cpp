class Solution {
public:
    int digit[100];
    long long findNthBaseK(int n, int k) {
        long long res = 0;

        int flen;
        int tmp = n;
        for (int len = 1; len < 1e3; len++) {
            int hlen = (len + 1) / 2;
            long long cnt = pow(k, hlen - 1) * (k - 1);
            if (cnt < tmp) {
                tmp -= cnt;
            } else {
                flen = len;
                break;
            }
        }

        int hlen = (flen + 1)/2;
        for (int i = 0; i < hlen; i++) {
            for (int j = (i != 0 ? 0 : 1); j < k; j++) {
                int remainLen = hlen - (i + 1);
                long long cnt = pow(k, remainLen);
                if (cnt < tmp) {
                    tmp -= cnt;
                } else {
                    res = res * k + j;
                    break;
                }
            }
        }
        long long x = res;
        if (flen&1) x /= 10;
        while (x) res = res * 10 + (x % k), x /= 10;
        return res;
    }
    long long kMirror(int k, int n) {
        auto isPalindrome = [&](long long x) -> bool {
            int length = -1;
            while (x) {
                ++length;
                digit[length] = x % k;
                x /= k;
            }
            for (int i = 0, j = length; i < j; ++i, --j) {
                if (digit[i] != digit[j]) {
                    return false;
                }
            }
            return true;
        };

        long long ans = 0;
        int cnt = 0;
        for (int i = 1; i <= 1e7; i++) {
            long long curNum = findNthBaseK(i, 10);
            // cout << i << ' ' << curNum << '\n';
            if (isPalindrome(curNum)) {
                ans += curNum;
                cnt++;
                if (cnt == n) {
                    break;
                }
            }
        }
        return ans;
    }
};