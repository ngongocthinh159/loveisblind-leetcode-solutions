class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cur = 0;

        for (int i = 0; i < nums.size();) {
            int start = i;
            int j = i;
            while (j + 1 < nums.size() && nums[j + 1] == nums[j]) {
                j++;
            }
            int len = j - start + 1;
            int willReplace = min(2, len);
            int cnt = 0;
            while (cnt < willReplace) {
                nums[cur] = nums[start];
                cnt++;
                cur++;
            }
            i = j + 1;
        }

        return cur;
    }
};