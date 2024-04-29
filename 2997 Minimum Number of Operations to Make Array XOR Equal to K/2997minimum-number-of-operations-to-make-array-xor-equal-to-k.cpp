class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans = 0;
        int cur = 0;
        for (auto x : nums) {
            cur ^= x;
        }
        for (int i = 31; i >= 0; i--) {
            if (((k>>i)&1) ^ ((cur>>i)&1)) ans++; 
        }
        return ans;
    }
};