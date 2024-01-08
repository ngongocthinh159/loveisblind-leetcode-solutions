class Solution {
public:
    bool check(vector<int> &v) {
        unordered_set<int> st(v.begin(), v.end());
        int mn = INT_MAX, mx = INT_MIN;
        for (int i = 0; i < v.size(); i++) {
            mn = min(mn, v[i]);
            mx = max(mx, v[i]);
        }
        if ((mx-mn)%((int) v.size() - 1)!=0) return false;
        int diff = (mx-mn)/((int) v.size() - 1);
        int cur = mn;
        for (int i = 0; i < v.size(); i++) {
            if (!st.count(cur)) return false;
            cur += diff;
        }
        return true;
    }
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& _l, vector<int>& _r) {
        vector<bool> res;
        for (int i = 0; i < _l.size(); i++) {
            vector<int> v(nums.begin() + _l[i], nums.begin() + _r[i] + 1);
            res.push_back(check(v));
        }
        return res;
    }
};