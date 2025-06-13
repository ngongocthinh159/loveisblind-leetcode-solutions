class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        int idx, n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == k) {
                idx = i;
                break;
            }
        }
        int L = 0, S = 0;
        unordered_map<int,int> freq;
        for (int i = idx; i < n; i++) {
            if (nums[i] > k) L++;
            else if (nums[i] < k) S++;
            freq[L - S]++;
        }
        L = 0, S = 0;
        int ans = 0;
        for (int i = idx; i >= 0; i--) {
            if (nums[i] > k) L++;
            else if (nums[i] < k) S++;
            int dif = L - S;
            ans += freq[-dif];
            ans += freq[-dif + 1];
        }
        return ans;
    }
};