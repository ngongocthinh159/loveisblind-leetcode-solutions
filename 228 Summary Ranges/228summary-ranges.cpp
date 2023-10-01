class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int i = 0;
        vector<string> res;
        while (i < nums.size()) {
            int start = i;
            int end = i;

            while (end + 1 < (int) nums.size()) {
                long long next = nums[end] + 1;
                if (nums[end+1] == next) end++;
                else break;
            }
            if (start != end) {
                res.push_back(to_string(nums[start])+"->"+to_string(nums[end]));
            } else res.push_back(to_string(nums[start]));
            i = end + 1;
        }
        return res;
    }
};