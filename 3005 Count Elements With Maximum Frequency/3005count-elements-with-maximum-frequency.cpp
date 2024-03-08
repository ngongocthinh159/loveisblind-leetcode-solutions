class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> cnt(100+1,0);
        int mx = INT_MIN;
        int ans;
        for (auto num : nums) {
            cnt[num]++;
            if (mx < cnt[num]) {
                mx = cnt[num];
                ans = cnt[num];
            } else if (mx==cnt[num]) {
                ans += cnt[num];
            }
        }
        return ans;
    }
};