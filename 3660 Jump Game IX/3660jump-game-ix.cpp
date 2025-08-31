class Solution {
public:
    /*
        Try segment [max, n - 1] (left most max)
        Then [second_max, max - 1] (lest most second_max)
    */
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> pref(n + 1);
        for (int i = 0; i < n; i++)
            pref[i + 1] = max(pref[i], nums[i]);
        unordered_map<int,int> pos;
        for (int i = n - 1; i >= 0; i--) pos[nums[i]] = i;
        int i = n - 1;
        int mn = 1e9, prev_mx = -1;
        vector<int> ans(n);
        while (i >= 0) {
            int mx = pref[i + 1];
            int j = pos[mx];
            
            if (mx > mn) {
                for (int k = j; k <= i; k++) ans[k] = prev_mx, mn = min(mn, nums[k]);
            } else {
                mn = 1e9;
                for (int k = j; k <= i; k++) ans[k] = mx, mn = min(mn, nums[k]);
                prev_mx = mx;
            }
            
            i = j - 1;
        }
        return ans;
    }
};