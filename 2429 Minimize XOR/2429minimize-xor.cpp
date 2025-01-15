class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int x = 0;
        int set_2 = __builtin_popcount(num2);
        for (int bit = 30; bit >= 0; bit--) {
            if (((num1 >> bit)&1) && set_2) {
                x |= (1 << bit);
                set_2--;
            }
        }
        for (int bit = 0; set_2 && bit <= 30; bit++) {
            if (!((num1 >> bit)&1)) {
                x |= (1 << bit);
                set_2--;
            }
        }
        return x;
    }
};