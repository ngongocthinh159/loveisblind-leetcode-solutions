class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int s1 = 0, s2 = 0;
        int n = nums1.size(), m = nums2.size();
        for (int i = 0; i < n; i++) {
            s1 += nums1[i];
        }
        for (int i = 0; i < m; i++) {
            s2 += nums2[i];
        }
        if (s1 > s2) {
            swap(nums1, nums2);
            swap(s1, s2);
            swap(n, m);
        }
        priority_queue<int> q;
        for (int i = 0; i < n; i++) q.push(6 - nums1[i]);
        for (int i = 0; i < m; i++) q.push(nums2[i] - 1);
        int dif = s2 - s1;
        int oper = 0;
        while (q.size() && dif) {
            int x = q.top();
            q.pop();
            int will = min(x, dif);
            dif -= will;
            oper++;
        }
        if (dif)
            return -1;
        return oper;
    }
};