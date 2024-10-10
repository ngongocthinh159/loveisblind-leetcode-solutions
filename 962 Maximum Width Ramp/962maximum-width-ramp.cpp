class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        vector<int> v;
        for (int i = n - 1; i >= 0; i--) {
            if (i == n - 1) v.push_back(i);
            else if (nums[i] > nums[v.back()]) v.push_back(i);
        }
        reverse(v.begin(), v.end());
        int j = 0;
        int ans = 0;
        for (int i = 0; i < n && j < v.size(); i++) {
            while (j < v.size() && v[j] <= i) j++; // ensure j always > i
            while (j < v.size() && nums[v[j]] >= nums[i]) { // find last True from left to right
                ans = max(ans, v[j] - i);
                j++;
            }
        }
        return ans;
    }
};