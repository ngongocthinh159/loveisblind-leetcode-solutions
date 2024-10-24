class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        vector<long long> gcdCnt(5e4 + 5);
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 1; j*j <= nums[i]; j++) {
                if (nums[i] % j == 0) {
                    gcdCnt[j]++;
                    if (nums[i] / j != j) gcdCnt[nums[i] / j]++;
                }
            }
        }

        for (int i = 5e4 + 5 - 1; i >= 1; i--) {
            if (gcdCnt[i]) {
                gcdCnt[i] = gcdCnt[i]*(gcdCnt[i] - 1)/2;
                for (int j = 2*i; j < 5e4 + 5; j += i) {
                    gcdCnt[i] -= gcdCnt[j];
                }
            }
        }
        vector<long long> v;
        vector<int> gcds;
        for (int i = 1; i < 5e4 + 5; i++) {
            if (gcdCnt[i] != 0) v.push_back(gcdCnt[i]), gcds.push_back(i);
        }
        for (int i = 1; i < v.size(); i++) v[i] += v[i - 1];

        vector<int> ans(queries.size());
        int j = 0;
        for (auto q : queries) {
            q++;
            auto it = lower_bound(v.begin(), v.end(), q);
            int idx = it - v.begin();
            ans[j] = gcds[idx];
            j++;
        }
        return ans;
    }
};