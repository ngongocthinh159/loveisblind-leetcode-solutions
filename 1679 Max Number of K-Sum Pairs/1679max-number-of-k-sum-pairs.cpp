class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0, r = n - 1;
        sort(nums.begin(), nums.end());
        int ans = 0;
        while (l < r) {
            if (nums[l] + nums[r] < k) {
                l++;
            } else if (nums[l] + nums[r] > k) {
                r--;
            } else {
                int sl = nums[l];
                int sr = nums[r];
                int cntl = 1;
                int cntr = 1;
                while (l + 1 < r && nums[l + 1] == sl) {
                    cntl++;
                    l++;
                }
                while (r - 1 > l && nums[r - 1] == sr) {
                    cntr++;
                    r--;
                }
                if (sl == sr) ans += (cntl+cntr)/2;
                else ans += min(cntl, cntr);
                
                l++; r--;
            }
        }
        return ans;
    }
};