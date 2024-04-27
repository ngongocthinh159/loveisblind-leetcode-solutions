class Solution {
public:
    int getMax(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> v(n);
        int sum1 = 0;
        for (int i = 0; i < n; i++) {
            v[i] = nums2[i] - nums1[i];
            sum1 += nums1[i];
        }
        int curMx = v[0];
        int mxSum = curMx;
        for (int i = 1; i < n; i++) {
            curMx = max(v[i], v[i] + curMx);
            mxSum = max(mxSum, curMx);
        }
        if (mxSum > 0) return sum1 + mxSum;
        return sum1;
    }
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        return max(getMax(nums1, nums2), getMax(nums2, nums1));        
    }
};