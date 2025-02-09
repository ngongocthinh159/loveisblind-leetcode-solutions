class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long ans = 0;
        unordered_map<int,int> M;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            ans += (i - M[nums[i] - i]);
            M[nums[i] - i]++;
        }
        return ans;
    }
};