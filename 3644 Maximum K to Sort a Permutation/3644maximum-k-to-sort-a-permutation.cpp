class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        // Imagine in the nums, we have:
        // + a group of numbers already in correct places a
        // + a group of numbers not in correct places => we only swap numbers those group
        // For each number in in-correct group, that number will be swapped at least 1 time
        // => The chosen k set bits should be subset of set bits of that number
        // => The chosen k set bits should be subset of set bits of each in-correct number

        // => The possible chosen k should be bitwise AND of all in-correct numbers (bit intersection)
        // And we also for sure that if we take k = bit intersection of all in-correct numbers then
        // k is already existed in nums (nums is permutation from 0 -> n, and bitwise AND only decrease)
        // => We now can use k as intermediate number for swap

        // Suppose we have two numbers in reversed pos [B, A], we need to reverse to [A, B]
        // We have 3 cases of k position compared to [B, A]:
        // + [k, B, A] => Swap (k, A) => [A, B, k]
        // + [B, k, A] => Swap (B, k) => [k, B, A] then Swap(k, A) => [A, B, k]
        // + [B, A, k] => Swap (B, k) => [k, A, B]
        // All 3 cases A and B is correct in order respect to each other,
        // to move k we can freely swap adjencent element of k
        // without changing order of other elements

        int ans = ~0;
        for (int i = 0; i < nums.size(); i++) if (nums[i] != i)
            ans &= nums[i];
        if (ans == ~0) return 0;
        return ans;
    }
};