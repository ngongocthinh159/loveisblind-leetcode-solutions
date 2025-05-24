class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), m = queries.size();
        int j = 0, cur = 0;
        vector<int> effect(n + 1);
        for (int i = 0; i < n; i++) {
            cur += effect[i];
            while (j < m && cur < nums[i]) {
                if (queries[j][1] >= i) {
                    if (queries[j][0] > i) {
                        effect[queries[j][0]] += queries[j][2];
                    } else {
                        cur += queries[j][2];
                    }
                    effect[queries[j][1] + 1] -= queries[j][2];
                } 
                j++;
            }
            if (cur < nums[i]) return -1;
        }
        return j;
    }
};