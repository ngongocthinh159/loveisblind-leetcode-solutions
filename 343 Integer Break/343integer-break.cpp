class Solution {
public:
    int integerBreak(int num) {
        if (num <= 3) return num - 1;
        if (num % 3 == 0) return pow(3,num/3);
        if (num % 3 == 1) {
            int cnt3 = ((int) num/3)-1;
            int cnt2 = 2;
            return pow(3,cnt3) * pow(2,cnt2);
        }
        if (num % 3 == 2) {
            int cnt3 = num/3;
            int cnt2 = 1;
            return pow(3,cnt3) * pow(2,cnt2);
        }
        return -1;
    }
};