class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> M;
        M[0] = -1;
        long long sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            int remain = sum%k;
            if (M.count(remain)) {
                if (i - M[remain] >= 2) return true;
            }
            else M[remain] = i;
        }
        return false;
    }
};