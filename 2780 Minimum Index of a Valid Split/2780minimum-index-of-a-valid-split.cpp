class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        vector<int> st1;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (!st1.size()) st1.push_back(nums[i]);
            else if (st1.back() == nums[i]) st1.push_back(nums[i]);
            else st1.pop_back();
        }
        int dominant = st1.back(), tot = 0;
        for (auto x : nums) if (x == dominant) tot++;
        // cout << dominant << " " << tot << "\n";
        int cnt = 0;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == dominant) cnt++;
            int remain = tot - cnt;
            int l1 = i + 1;
            int l2 = n - l1;
            if (cnt >= l1/2 + 1 && remain >= l2/2 + 1) return i;
        }
        return -1;
    }
};