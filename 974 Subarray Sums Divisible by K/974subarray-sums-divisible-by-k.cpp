class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        freq[0] = 1;
        int n = nums.size();
        long long sum = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            sum %= k;
            if (sum < 0) sum += k;
            ans += freq[sum];
            freq[sum]++;
        }
        return ans;
    }
};