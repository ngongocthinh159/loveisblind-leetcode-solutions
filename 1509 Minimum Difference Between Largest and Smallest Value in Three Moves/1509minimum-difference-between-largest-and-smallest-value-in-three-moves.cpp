class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if (n <= 4) return 0;
        vector<int> mn(4, INT_MAX);
        vector<int> mx(4, INT_MIN);
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < mn.size(); i++) {
                if (nums[k] <= mn[i]) {
                    for (int j = mn.size() - 1; j >= i + 1; j--) {
                        mn[j] = mn[j - 1];
                    }

                    mn[i] = nums[k];
                    break;
                }
            }
            for (int i = mx.size() - 1; i >= 0; i--) {
                if (nums[k] >= mx[i]) {
                    for (int j = 0; j <= i - 1; j++) {
                        mx[j] = mx[j + 1];
                    }
                    
                    mx[i] = nums[k];
                    break;
                }
            }
        }
        int ans = INT_MAX;
        for (int start = 0; start <= 3; start++) {
            int end = 3 - start;
            ans = min(ans, mx[3 - end] - mn[start]);
        }
        return ans;
    }
};