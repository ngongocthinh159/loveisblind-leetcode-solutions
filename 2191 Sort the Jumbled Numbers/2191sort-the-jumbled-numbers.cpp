class Solution {
public:
    struct comparator {
        bool operator() (const vector<long long>&v1, const vector<long long> &v2) const {
            if (v1[0] < v2[0]) return true;
            if (v1[0] == v2[0] && v1[1] < v2[1]) return true;
            return false;
        }
    };
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<vector<long long>> v;
        int x;
        for (int i = 0; i < nums.size(); i++) {
            x = nums[i];
            v.push_back({get_mapped(x, mapping), i, 1LL*x});
        }
        sort(v.begin(), v.end(), comparator());
        vector<int> res;
        for (auto &x : v) {
            res.push_back((int) x[2]);
        }
        return res;
    }
    long long get_mapped(int x, vector<int> &mapping) {
        if (x == 0) return mapping[0];
        long long mapped = 0;
        long long digit;
        long long cur = 1;
        while (x > 0) {
            digit = x%10;
            mapped += cur*mapping[digit];
            x /= 10;
            cur *= 10;
        }
        return mapped;
    }
};