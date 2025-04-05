class Solution {
public:
    // count how many subset have i-th bit set:
    // suppose we have m elements have i-th bit set
    // then the subset have i-th bit set will have odd numbers of those i-th bit set element
    // 2^(n - m) * (1Cm + 3Cm + 5Cm + ...)
    // 2^(n - m) * 2^(m - 1) = 2^(n - 1)
    // => As long as 1 element has i-th set, then there will be 2^(n - 1) subset's xor total has i-th bit set
    int subsetXORSum(vector<int>& nums) {
        int res = 0, n = nums.size();
        for (auto x : nums) res |= x;
        return res << (n - 1);
    }
};