class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans;
        int cnt = 1;
        while (cnt <= 32) {
            ans <<= 1;
            if (n&1) {
                ans |= 1;
            }
            n >>= 1;
            cnt++;
        }
        return ans;
    }
};