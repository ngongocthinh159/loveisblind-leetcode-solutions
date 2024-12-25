class Solution {
public:
    int reverse(int x) {
        char sign = x >= 0 ? '+' : '-';
        int res = 0;
        int IINF = sign == '+' ? INT_MAX : INT_MIN;
        while (x != 0) {
            int digit = abs(x%10);
            if (sign == '+') {
                if (res <= IINF/10) res *= 10;
                else return 0;
                if (res <= IINF - digit) res += digit;
                else return 0;
            } else {
                if (res >= ceil(IINF/10)) res *= 10;
                else return 0;
                if (res >= IINF + digit) res -= digit;
                else return 0;
            }
            x /= 10;
        }
        return res;
    }
};