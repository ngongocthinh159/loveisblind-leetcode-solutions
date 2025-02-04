#define next __next
class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        int next = nums[n - 1];
        int ans = next;
        for (int i = n - 2; i >= 0; i--) {
            int cur = nums[i];
            if (nums[i + 1] > nums[i]) cur += next;
            ans = max(ans, cur);
            next = cur;
        }
        return ans;
    }
};