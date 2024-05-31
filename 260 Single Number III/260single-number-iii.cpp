class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int _xor = 0;
        for (auto x : nums) {
            _xor ^= x;
        }
        int first_bit_set = 0;
        for (int i = 0; i <= 31; i++) {
            if ((_xor >> i) & 1) {
                first_bit_set = i;
                break;
            }
        }
        int a = 0;
        for (auto x : nums) {
            if ((x >> first_bit_set) & 1) a ^= x;
        }
        return {a, _xor^a};
    }
};