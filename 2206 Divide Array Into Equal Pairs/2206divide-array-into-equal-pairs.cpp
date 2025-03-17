class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int freq[501];
        for (auto x : nums) freq[x]++;
        for (auto x : nums) if (freq[x] & 1) return false;
        return true;
    }
};