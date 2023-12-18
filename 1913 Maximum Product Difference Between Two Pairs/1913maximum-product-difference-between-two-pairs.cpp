class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int max1 = INT_MIN, max2 = INT_MIN, min1 = INT_MAX, min2 = INT_MAX;
        for (auto num : nums) {
            if (max2 < num) {
                max1 = max2; max2 = num;
            } else if (max1 < num) max1 = num;
            if (min1 > num) {
                min2 = min1; min1 = num;
            } else if (min2 > num) min2 = num;
        }
        return max1*max2 - min1*min2;
    }
};