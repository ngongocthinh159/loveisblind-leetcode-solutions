class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        int n = nums.size();
        vector<long long> d1(n + 2), d2(n + 2), d3(n + 2);
        vector<long long> pref(n + 1);
        for (int i = 0; i < n; i++) pref[i + 1] = pref[i] + nums[i];
        d3[n] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            if (d3[i + 2] >= 0 && nums[i + 1] > nums[i]) 
                d3[i + 1] = d3[i + 2] + nums[i];
            else
                d3[i + 1] = nums[i];
        }
        d1[n] = d2[n] = 1;
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i + 1] > nums[i]) 
                d1[i + 1] = d1[i + 2] + 1;
            else
                d1[i + 1] = 1;
            if (nums[i + 1] < nums[i]) 
                d2[i + 1] = d2[i + 2] + 1;
            else
                d2[i + 1] = 1;
        }
        long long ans = LLONG_MIN;
        for (int i = 0; i < n; i++) {
            if (d1[i + 1] != 1) {
                int j = i + d1[i + 1] - 1;
                if (d2[j + 1] != 1) {
                    int k = j + d2[j + 1] - 1;
                    if (d1[k + 1] != 1) {
                        ans = max(ans, pref[k + 1] - pref[i] + d3[k + 2]);
                    }
                }
            }
        }
        return ans;
    }
};