/*
For any pairs (a,b):

Takes 0 move to form sum a+b
Takes 1 move to form sum in range [min(a, b) + 1, max(a, b) + Limit] except sum mentioned in (1)
Takes 2 moves to form any sum outside range mentioned in (2)
Then you can map these critical points as range updates onto a diff array. Note your diff array should have length = 2 * limit as that's the maximum pair sum attainable.

--------|-------|------
        a       b
*/

class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> opers(2*limit + 2);
        int cur = 0;
        for (int i = 0; i < n/2; i++) {
            opers[2] += 2;
            opers[2*limit + 1] -= 2;
            opers[min(nums[i], nums[n - i - 1]) + 1] -= 1;
            opers[max(nums[i], nums[n - i - 1]) + limit + 1] += 1;
            opers[nums[i] + nums[n - i - 1]] -= 1;
            opers[nums[i] + nums[n - i - 1] + 1] += 1;
        }
        int ans = INT_MAX;
        for (int i = 2; i <= 2*limit; i++) {
            cur += opers[i];
            ans = min(ans, cur);
        }
        return ans;
    }
};