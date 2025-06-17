bitset<2055> S2;
bitset<2055> S3;
class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        S2.reset();
        S3.reset();
        int n = nums.size();
        int mxbit = 0;
        for (int i = 0; i < n; i++) {
            int msb = 32 - __builtin_clz(nums[i]) - 1;
            mxbit = max(mxbit, msb);
            for (int j = 0; j < i; j++) S2[nums[i] ^ nums[j]] = 1;
        }

        for (int i = 0; i < (1 << (mxbit + 1)); i++) {
            for (int j = 0; j < n; j++) {
                if (S2[nums[j] ^ i]) S3[i] = 1;
            }
        }
        for (int i = 0; i < n; i++) S3[nums[i]] = 1;

        return S3.count();
    }
};