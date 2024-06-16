class Solution {
public:
    // If we are currently cover range: [0, k]
    // Then we add a number x: We can cover an additional range [x, k + x] => Total range: [0, k + x]
    // To let two ranges continuous and optimal: the max x will be k + 1
    // For x = k + 1, Total range: [0, 2k + 1]
    int minPatches(vector<int>& nums, int n) {
        long long cur = 0; // cur range: [0, cur]
        int patch = 0;
        for (int i = 0; cur < n;) {
            if (i < nums.size() && !(cur < nums[i] - 1)) { // add numbers of array to current range while we can add
                cur += nums[i];

                // Increase i after adding, we can not use this nums[i] second time to create new range
                // because to reach new range: [0, cur + nums[i]] from [0, cur]
                // we must use nums[i]
                i++; 
            } else { // If we used all nums[i] <= cur range + 1   => We must add new optimal num = cur + 1
                cur += cur + 1; // new range: [0, 2cur + 1]
                patch++; // Add new num: cur + 1
            }
        }
        return patch;
    }
};