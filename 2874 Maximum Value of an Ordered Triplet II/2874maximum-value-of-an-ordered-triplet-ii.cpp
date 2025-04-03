class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> L(n + 1), R(n + 2);
        for (int i = 0; i < n; i++) {
            L[i + 1] = max(L[i], nums[i]);
        }
        for (int i = n - 1; i >= 0; i--) {
            R[i + 1] = max(R[i + 2], nums[i]);
        }
        long long ans = LLONG_MIN;
        for (int i = 1; i < n - 1; i++) {
            ans = max(ans, 1LL * (L[i] - nums[i]) * R[i + 2]);
        }
        return max(0LL, ans);
    }
};