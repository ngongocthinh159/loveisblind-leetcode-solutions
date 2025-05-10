class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0, sum2 = 0;
        bool f1 = false, f2 = false;
        for (int i = 0; i < nums1.size(); i++) {
            if (nums1[i] == 0) 
                sum1 += 1, f1 = true;
            else
                sum1 += nums1[i];
        }
        for (int i = 0; i < nums2.size(); i++) {
            if (nums2[i] == 0)
                sum2 += 1, f2 = true;
            else
                sum2 += nums2[i];
        }
        if (f1 && f2) return max(sum1, sum2);
        if (!f1 && !f2) {
            if (sum1 != sum2) return -1;
            return sum1;
        }
        if (!f2) swap(sum1, sum2);
        if (sum2 <= sum1) return sum1;
        return -1;
    }
};