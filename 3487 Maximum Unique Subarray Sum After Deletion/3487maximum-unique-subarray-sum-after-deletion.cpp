class Solution {
public:
    int maxSum(vector<int>& nums) {
        bool canPos = false;
        bool canZero = false;
        int mxNeg = INT_MIN;
        unordered_set<int> posUnique;
        for (auto x : nums) {
            if (x > 0) canPos = true, posUnique.insert(x);
            if (x == 0) canZero = true;
            if (x < 0) mxNeg = max(mxNeg, x);
        }
        int posSum = 0;
        for (auto x : posUnique) posSum += x;
        if (canPos)
            return posSum;
        if (canZero)
            return 0;
        return mxNeg;
    }
};