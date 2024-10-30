class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> bestEnding;
        vector<int> dp1(n);
        vector<int> dp2(n);
        for (int i = 0; i < n; i++) {
            auto it = lower_bound(bestEnding.begin(), bestEnding.end(), nums[i]);
            if (it == bestEnding.end()) bestEnding.push_back(nums[i]);
            else bestEnding[it - bestEnding.begin()] = nums[i];
            dp1[i] = bestEnding.size();
            // cout << dp1[i] << " ";
        }
        // cout << "\n";
        bestEnding.clear();
        for (int i = n - 1; i >= 0; i--) {
            auto it = lower_bound(bestEnding.begin(), bestEnding.end(), nums[i]);
            if (it == bestEnding.end()) bestEnding.push_back(nums[i]);
            else bestEnding[it - bestEnding.begin()] = nums[i];
            dp2[i] = bestEnding.size();
        }
        // for (int i = 0; i < n; i++) {
        //     cout << dp2[i] << " "; 
        // }
        int ans = 0;
        for (int i = 1; i < n - 1; i++) {
            if (dp1[i] >= 2 && dp2[i] >= 2) ans = max(ans, dp1[i] + dp2[i] - 1);
        }
        return n - ans;
    }
};