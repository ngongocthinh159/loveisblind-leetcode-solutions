class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prf(n + 1);
        for (int i = 1; i <= n; i++) {
            prf[i] = prf[i - 1] + (nums[i - 1]&1 ? 1 : 0);
        }
        unordered_map<int,int> M;
        M[prf[0] + k] = 1;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (M.count(prf[i + 1])) ans += M[prf[i + 1]];
            M[prf[i + 1] + k]++;
        }
        return ans;
    }
};