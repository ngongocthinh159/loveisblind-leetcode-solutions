#define ll long long
class Solution {
public:
    int n, K;
    vector<vector<int>> g;
    const ll LINF = 1e18;
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        n = nums.size();
        K = k;
        g.resize(n); 
        for (auto &e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        vector<int> pos;
        vector<int> neg;
        ll res = 0;
        for (int i = 0; i < n; i++) {
            res += nums[i];
            int x = (nums[i]^k) - nums[i];
            if (x > 0) {
                pos.push_back(x);
            } else
                neg.push_back(x);
        }
        sort(pos.begin(), pos.end());
        sort(neg.begin(), neg.end());
        if ((pos.size()) & 1) {
            for (int i = 1; i < pos.size(); i++) res += pos[i];
            if (neg.size() && abs(neg.back()) < pos[0]) {
                res += pos[0] - abs(neg.back());
            }
        } else {
            for (int i = 0; i < pos.size(); i++) res += pos[i];
        }
        return res;
    }
};