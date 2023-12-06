class Solution {
public:
    int totalMoney(int n) {
        int w = n / 7;
        int remain = n%7;
        int res = w*(1 + 1 + 6)*7/2 + 7*w*(w-1)/2 + (w + 1 + w + 1 + remain - 1)*remain/2;
        return res;
    }
};