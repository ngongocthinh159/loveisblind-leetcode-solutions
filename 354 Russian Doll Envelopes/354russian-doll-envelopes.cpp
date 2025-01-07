class Solution {
public:
    int lis(vector<int> &nums) {
        vector<int> best_ending;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            auto it = lower_bound(best_ending.begin(), best_ending.end(), nums[i]);
            if (it == best_ending.end()) best_ending.push_back(nums[i]);
            else {
                int idx = it - best_ending.begin();
                best_ending[idx] = nums[i];
            }
        }
        return best_ending.size();
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        sort(envelopes.begin(), envelopes.end(), [&](vector<int> &p1, vector<int> &p2) {
            if (p1[0] < p2[0]) return true;
            if (p1[0] == p2[0] && p1[1] > p2[1]) return true;
            return false;
        });
        vector<int> v(n);
        for (int i = 0; i < n; i++) v[i] = envelopes[i][1];
        return lis(v);
    }
};