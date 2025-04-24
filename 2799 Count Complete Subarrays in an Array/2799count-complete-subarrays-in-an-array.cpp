#define N 2005
int uniq[N], freq[N];
class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size(), unique = 0;
        for (auto x : nums) if (++uniq[x] == 1) unique++;
        for (auto x : nums) --uniq[x];
        int cnt = 0, ans = 0, l = 0;
        for (int r = 0; r < n; r++) {
            if (++freq[nums[r]] == 1) cnt++;
            while (l <= r && cnt == unique) {
                if (--freq[nums[l++]] == 0) cnt--;
            }
            ans += l;
        }
        while (l < n) --freq[nums[l++]];
        return ans;
    }
};