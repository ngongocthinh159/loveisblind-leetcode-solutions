class Solution {
public:
    long long LINF = 1e11;
    long long cnt1(long long limit, vector<int> &nums1, vector<int> &nums2) {
        long long res = 0;
        int n = nums1.size(), m = nums2.size();
        for (int i = 0, l = m - 1; i < n; i++) {
            while (l >= 0 && 1LL * nums1[i] * nums2[l] > limit) l--;
            res += l + 1;
        }
        return res;
    }
    long long cnt2(long long limit, vector<int>&nums1, vector<int> &nums2) {
        long long res = 0;
        int n = nums1.size(), m = nums2.size();
        for (int i = 0, l = 0; i < n; i++) {
            while (l < m && 1LL * nums1[i] * nums2[l] <= limit) l++;
            res += l;
        }
        return res;
    }
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        vector<int> pos1, neg1;
        vector<int> pos2, neg2;
        for (int i = 0; i < nums1.size(); i++) {
            if (nums1[i] >= 0) pos1.push_back(nums1[i]);
            else neg1.push_back(nums1[i]);
        }
        for (int i = 0; i < nums2.size(); i++) {
            if (nums2[i] >= 0) pos2.push_back(nums2[i]);
            else neg2.push_back(nums2[i]);
        }

        long long l = -LINF, r = LINF;
        while (r - l > 1) {
            long long m = l + (r - l)/2;
            long long cnt = 0;
            
            cnt += cnt1(m, pos1, pos2); // cnt1, correct pos1, pos2
            
            reverse(neg1.begin(), neg1.end());
            reverse(neg2.begin(), neg2.end());
            cnt += cnt1(m, neg1, neg2); // cnt1, correct neg1, reverse neg2
            reverse(neg1.begin(), neg1.end());
            reverse(neg2.begin(), neg2.end());
    
            cnt += cnt2(m, pos1, neg2);

            reverse(pos2.begin(), pos2.end());
            cnt += cnt1(m, neg1, pos2);
            reverse(pos2.begin(), pos2.end());

            if (cnt < k)
                l = m;
            else 
                r = m;
        }
        return l + 1;
    }
};