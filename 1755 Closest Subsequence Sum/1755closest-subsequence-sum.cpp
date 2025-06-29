bitset<80000001> sum;
class Solution {
public:
    void gen(int i, int len, int cur, vector<long long> &A, vector<int> &nums) {
        if (i == len) {
            A.push_back(cur);
            return;
        }
        gen(i + 1, len, cur, A, nums);
        gen(i + 1, len, cur + nums[i], A, nums);
    }
    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size();
        vector<long long> A, B;
        int half = (n + 1)/2;
        gen(0, half, 0, A, nums);
        gen(half, n, 0, B, nums);
        // sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        B.erase(unique(B.begin(), B.end()), B.end());
        long long ans = 1e9;
        for (int i = 0; i < A.size(); i++) {
            long long tar = goal - A[i];
            auto it1 = lower_bound(B.begin(), B.end(), tar);
            auto it2 = upper_bound(B.begin(), B.end(), tar);
            if (it1 != B.end()) {
                ans = min(ans, (A[i] + *it1) - goal);
            }
            if (it2 != B.begin()) {
                it2--;
                ans = min(ans, goal - (A[i] + *it2));
            }
        }
        return static_cast<int>(ans);
    }
};