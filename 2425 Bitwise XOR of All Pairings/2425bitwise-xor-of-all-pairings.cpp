class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int res = 0;
        int n1 = nums1.size(), n2 = nums2.size();
        if (n2&1) for (auto x : nums1) res ^= x;
        if (n1&1) for (auto x : nums2) res ^= x;
        return res;
    }
};