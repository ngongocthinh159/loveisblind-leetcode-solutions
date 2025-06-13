class Solution {
public:
    int sumImbalanceNumbers(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int x = nums[i];

            int R = i + 1;
            int idxR = -1;
            while (R < n && nums[R] != x + 1 && nums[R] != x) {
                if (nums[R] - x > 1 && idxR == -1) idxR = R;
                R++;
            }
            R--;
            
            int L = i - 1;
            int idxL = -1;
            while (L >= 0 && nums[L] != x + 1) {
                if (nums[L] - x > 1 && idxL == -1) idxL = L;
                L--;
            }
            L++;

            if (idxR != -1) {
                ans += (R - idxR + 1) * (i - L + 1);
            }
            if (idxL != -1) {
                ans += (idxL - L + 1) * (R - i + 1);
            }
            if (idxL != -1 && idxR != -1) {
                ans -= (R - idxR + 1) * (idxL - L + 1);
            }
        }
        return ans;
    }
};