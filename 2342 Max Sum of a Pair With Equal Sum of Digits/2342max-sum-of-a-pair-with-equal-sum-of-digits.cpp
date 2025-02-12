class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int,int> M;
        int n = nums.size();
        int ans = -1;
        for (int i = 0; i < n; i++) {
            int d_sum = 0;
            int num = nums[i];
            while (num) {
                d_sum += num%10;
                num /= 10;
            }
            if (M.count(d_sum)) ans = max(ans, nums[i] + M[d_sum]);
            M[d_sum] = max(M[d_sum], nums[i]);
        }
        return ans;
    }
};