class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n = nums.size();
        int cnt = 0;
        long long ans = 0;
        unordered_map<int,int> freq;
        freq[0] = 1;
        for (int r = 0; r < n; r++) {
            if (nums[r] % modulo == k) cnt++;
            int target = ((cnt - k) + modulo) % modulo;
            ans += freq[target];
            freq[cnt%modulo]++;
        }
        return ans;
    }
};