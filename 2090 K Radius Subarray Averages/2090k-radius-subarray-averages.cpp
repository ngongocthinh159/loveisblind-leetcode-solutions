class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int w_size = 2*k + 1;
        if (w_size > nums.size()) {
            return vector<int>(nums.size(), -1);
        }
        if (k == 0) return nums;
        vector<int> res;
        long long sum = 0;
        for (int i = 0; i < k; i++) {
            res.push_back(-1);
            sum += nums[i];
        }
        for (int i = k; i < w_size; i++) {
            sum += nums[i];
        }
        res.push_back(sum/w_size);
        for (int i = w_size; i < nums.size(); i++) {
            sum += nums[i];
            sum -= nums[i - (2*k + 1)];
            res.push_back(sum/w_size);
        }
        for (int i = 0; i < k; i++) {
            res.push_back(-1);
        }
        return res;
    }
};