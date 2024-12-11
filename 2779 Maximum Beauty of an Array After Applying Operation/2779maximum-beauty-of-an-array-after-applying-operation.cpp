class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int mx = *max_element(nums.begin(), nums.end()) + k;
        int mn = *min_element(nums.begin(), nums.end()) - k;
        vector<int> freq(mx - mn + 1 + 1);
        int n = freq.size();
        for (auto x : nums) {
            freq[x - k - mn]++;
            if (x + k + 1 - mn < n) freq[x + k + 1 - mn]--;
        }
        for (int i = 1; i < n; i++) {
            freq[i] = freq[i] + freq[i - 1]; 
        }
        int ans = -1;
        for (int i = 0; i < n; i++) {
            ans = max(ans, freq[i]);
        }
        return ans;
    }
};