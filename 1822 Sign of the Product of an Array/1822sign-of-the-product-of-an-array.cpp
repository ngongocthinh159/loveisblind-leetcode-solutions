class Solution {
public:
    int arraySign(vector<int>& nums) {
        bool zero = false;
        bool pos = true;
        for (auto x : nums) {
            if (x == 0) zero = true;
            if (x < 0) pos ^= 1;
        }
        if (zero) return 0;
        if (pos) return 1;
        return -1;
    }
};