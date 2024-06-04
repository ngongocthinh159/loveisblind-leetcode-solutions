class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        vector<int> nearestIdxUnsetBit(32, -1);
        int ans = INT_MAX;
        for (int i = nums.size() - 1; i >= 0; i--) {
            set<int> S;
            for (int bit = 31; bit >= 0; bit--) {
                if (nums[i] & (1 << bit)) {
                    if (nearestIdxUnsetBit[bit] != -1) S.insert(nearestIdxUnsetBit[bit]);
                } else {
                    nearestIdxUnsetBit[bit] = i;
                }
            }
            int cur = nums[i];
            ans = min(ans, abs(cur - k));
            for (auto x : S) {
                cur = cur & nums[x];
                ans = min(ans, abs(cur - k));
            }
        }
        return ans;
    }
};