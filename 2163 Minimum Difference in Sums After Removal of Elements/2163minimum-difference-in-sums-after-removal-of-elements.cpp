class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n3 = nums.size();
        int n = n3 / 3;
        priority_queue<int> ql, qr;
        vector<long long> mnl(n3), mxr(n3);
        long long suml = 0, sumr = 0;
        for (int i = 0; i < n3; i++) {
            suml += nums[i];
            ql.push(nums[i]);
            while (ql.size() > n) {
                suml -= ql.top();
                ql.pop();
            }
            mnl[i] = suml;
        }
        for (int i = n3 - 1; i >= 0; i--) {
            sumr += nums[i];
            qr.push(-nums[i]);
            while (qr.size() > n) {
                sumr += qr.top();
                qr.pop();
            }
            mxr[i] = sumr;
        }
        long long ans = 2e18;
        for (int i = n - 1; i < 2*n; i++) {
            ans = min(ans, mnl[i] - mxr[i + 1]);
        }
        return ans;
    }
};