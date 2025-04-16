class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        long long cnt = 0, res = 0;
        bool found = false;
        unordered_map<int,int> freq;
        for (int r = 0, l = 0; r < n; r++) {
            cnt += freq[nums[r]];
            freq[nums[r]]++;
            while (l < r && cnt >= k) {
                found = true;
                cnt -= freq[nums[l]] - 1;
                freq[nums[l++]]--;
            }

            if (found) {
                res += l;
            }
        }
        return res;
    }
};