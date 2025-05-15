class Solution {
public:
    const int IINF = 1e9;
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) 
            return findMedianSortedArrays(nums2, nums1);
        int n = nums1.size(), m = nums2.size();
        bool singleMedian = (n + m)&1;
        int half = (n + m + 1)/2;
        int l = -2, r = n;
        while (r - l > 1) {
            int l1 = l + (r - l)/2;
            int r1 = l1 + 1;
            int l2 = half - (l1 + 1) - 1;
            int r2 = l2 + 1;
            
            int v_l1 = l1 == -1 ? -IINF : nums1[l1];
            int v_r1 = r1 == n ? IINF : nums1[r1];
            int v_l2 = l2 == -1 ? -IINF : nums2[l2];
            int v_r2 = r2 == m ? IINF : nums2[r2];
            
            if (v_l1 <= v_r2 && v_l2 <= v_r1) {
                if (singleMedian) 
                    return max(v_l1, v_l2);
                else
                    return 1.00 * (max(v_l1, v_l2) + min(v_r1, v_r2)) / 2;
            }

            if (v_l1 > v_r2)
                r = l1;
            else if (v_l2 > v_r1)
                l = l1;
        }

        return -1;
    }
};