class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> bit(32, 0);
        for (auto x : nums) {
            for (int i = 31; i >= 0; i--) {
                if ((x>>i) & 1) bit[i]++;
            }
        }
        int res = 0;
        for (int i = 31; i >= 0; i--) {
            if (bit[i] > 0 && bit[i]%3 != 0) res = res | (1 << i);
        }
        return res;
    }
};