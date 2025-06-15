class Solution {
public:
    const int MOD = 1e9 + 7;
    int specialTriplets(vector<int>& nums) {
        int n = nums.size();
        vector<int> L(n), R(n);
        unordered_map<int,int> freq;
        for (int i = 0; i < n; i++) {
            L[i] = freq[nums[i] * 2];
            freq[nums[i]]++;
        }
        freq.clear();
        long long ans = 0;
        for (int i = n - 1; i >= 0; i--) {
            R[i] = freq[nums[i] * 2];
            ans += 1LL * L[i] * R[i] % MOD;
            if (ans >= MOD) ans -= MOD;
            freq[nums[i]]++;
        }
        return ans;
    }
};