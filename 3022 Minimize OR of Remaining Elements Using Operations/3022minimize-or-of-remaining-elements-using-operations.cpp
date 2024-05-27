class Solution {
public:
    int minOrAfterOperations(vector<int>& nums, int k) {
        int mask = 0;
        for (int bit = 30; bit >= 0; bit--) {
            int cur_mask = mask | (1 << bit);
            bool ok = false;

            int cnt = 0;
            int _cur = -1, _prev = -1;
            for (int i = 0; i < nums.size();) {
                int cur = nums[i];
                while (i + 1 < nums.size() && (cur & cur_mask) != 0) {
                    cnt++;
                    cur = cur & nums[i + 1];
                    i++;
                }
                _prev = _cur;
                _cur = cur;
                i++;
            }

            if ((_cur & cur_mask) != 0) {
                if (_prev != -1 && (_prev & _cur & cur_mask) == 0) {
                    cnt++;
                    if (cnt <= k) ok = true;
                }
            } else {
                if (cnt <= k) ok = true;
            }

            if (ok) mask = mask | (1 << bit);
        }
        int res = 0;
        for (int bit = 30; bit >= 0; bit--) {
            if (!((mask >> bit) & 1)) res = res | (1 << bit);
        }
        return res;
    }
};