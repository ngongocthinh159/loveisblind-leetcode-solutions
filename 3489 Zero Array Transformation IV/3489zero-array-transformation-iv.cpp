class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& q) {
        int n = nums.size(), m = q.size();
        int mx = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) continue;
            bitset<1001> cur;
            cur[0] = 1;
            bool found = false;
            for (int j = 0; j < m; j++) {
                if (q[j][0] <= i && i <= q[j][1]) {
                    cur = cur | (cur << q[j][2]);
                    if (cur[nums[i]]) {
                        found = true;
                        mx = max(mx, j + 1);
                        break;
                    }
                }
            }
            if (!found)
                return -1;
        }
        return mx;
    }
};