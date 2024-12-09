class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int m = queries.size();
        vector<int> furthest(n);
        int l = 0, r = 0;
        while (r < n) {
            if (r != 0 && !((nums[r]+nums[r - 1])&1)) l = r;

            furthest[r] = l;

            r++;
        }
        
        vector<bool> ans(m);
        for (int i = 0; i < m; i++) {
            if (queries[i][0] >= furthest[queries[i][1]]) ans[i] = true;
            else ans[i] = false;
        }
        return ans;
    }
};