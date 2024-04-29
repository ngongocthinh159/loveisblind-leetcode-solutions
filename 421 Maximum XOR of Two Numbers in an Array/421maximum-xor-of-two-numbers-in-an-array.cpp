class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());
        if (mx == 0) return 0;
        int MSB = __lg(mx);
        int mxXor = 0;
        set<int> prf; 
        for (int i = MSB; i >= 0; i--) {
            mxXor <<= 1;
            int curXor = mxXor | 1;
            prf.clear();
            for (auto &x : nums) prf.insert((x>>i));
            for (auto &x : prf) {
                if (prf.count(x^curXor)) {
                    mxXor = curXor;
                    break;
                }
            }
        }
        return mxXor;
    }
};