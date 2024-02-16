class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        long long x2 = 0, tmp = x;
        while (tmp != 0) {
            x2 = x2*10 + tmp%10;
            tmp /= 10;
        }
        return x2 == x;
    }
};